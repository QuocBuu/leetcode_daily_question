#include <stdlib.h>
#include <string.h>

// Half of max 64-bit integer prevents addition overflow during DP transitions.
const long long kInfinity = 9223372036854775807LL / 2;
const int kFreqDecr = -1;
const int kFreqIncr = 1;

// Maintains dynamic prefix frequencies and value sums for sliding windows.
typedef struct {
    int treeSz;
    long long* tree;
} FenwickTree;

FenwickTree* createTree(int treeSz) {
    FenwickTree* ft = (FenwickTree*)malloc(sizeof(FenwickTree));
    ft->treeSz = treeSz;
    ft->tree = (long long*)calloc(treeSz + 1, sizeof(long long));
    return ft;
}

void freeTree(FenwickTree* ft) {
    free(ft->tree);
    free(ft);
}

// Propagates point frequency or value delta across covering tree intervals.
void addVal(FenwickTree* ft, int idx, long long num) {
    for (; idx <= ft->treeSz; idx += idx & -idx) {
        ft->tree[idx] += num;
    }
}

// Aggregates cumulative count or sum for compressed ranks up to idx.
long long queryPref(FenwickTree* ft, int idx) {
    long long sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += ft->tree[idx];
    }
    return sum;
}

// Binary-lifts over tree bit-intervals to locate the k-th order statistic.
int findKth(FenwickTree* ft, long long medianIdx) {
    int currIdx = 0;
    long long sum = 0;
    int maxBitIdx = 0;
    
    while ((1 << (maxBitIdx + 1)) <= ft->treeSz) {
        maxBitIdx++;
    }

    for (int step = 1 << maxBitIdx; step > 0; step >>= 1) {
        int nextIdx = currIdx + step;
        // Advance rank if cumulative frequency stays strictly below target.
        if (nextIdx <= ft->treeSz && sum + ft->tree[nextIdx] < medianIdx) {
            currIdx = nextIdx;
            sum += ft->tree[nextIdx];
        }
    }
    
    return currIdx + 1;
}

// Maps an element value to its 1-based rank among sorted unique array values.
int getCompressedId(int* uniqueNums, int uniqueTot, int target) {
    int l = 0, r = uniqueTot - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (uniqueNums[m] == target) return m + 1;
        if (uniqueNums[m] < target) l = m + 1;
        else r = m - 1;
    }
    return 1;
}

int cmpInts(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}

long long callWndwCost(
    FenwickTree* valFreqs,
    FenwickTree* sums,
    int* uniqueNums,
    int uniqueTot,
    int subarrSz
) {
    // 9. Locate the window median via binary lifting on the frequency tree.
    long long medianIdx = (subarrSz + 1) / 2;
    int medianId = findKth(valFreqs, medianIdx);
    long long medianValue = uniqueNums[medianId - 1];
    
    // 10. Partition window sums around the median to compute total L1 distance.
    long long leftCnt = queryPref(valFreqs, medianId);
    long long leftSum = queryPref(sums, medianId);
    long long totalSum = queryPref(sums, uniqueTot);
    long long rightCnt = subarrSz - leftCnt;
    long long rightSum = totalSum - leftSum;
    
    return (medianValue * leftCnt - leftSum) + (rightSum - medianValue * rightCnt);
}

long long* calcWndwCosts(int* nums, int numsSize, int subarrSz) {
    long long* wndwCosts = (long long*)malloc(numsSize * sizeof(long long));
    int* uniqueNums = (int*)malloc(numsSize * sizeof(int));
    memcpy(uniqueNums, nums, numsSize * sizeof(int));
    
    // 5. Coordinate-compress input values into compact 1-based Fenwick ranks.
    qsort(uniqueNums, numsSize, sizeof(int), cmpInts);
    int uniqueTot = 0;
    if (numsSize > 0) {
        uniqueNums[0] = uniqueNums[0];
        uniqueTot = 1;
        for (int i = 1; i < numsSize; i++) {
            if (uniqueNums[i] != uniqueNums[uniqueTot - 1]) {
                uniqueNums[uniqueTot++] = uniqueNums[i];
            }
        }
    }

    // 6. Create dual Fenwick trees for window element frequencies and sums.
    FenwickTree* valFreqs = createTree(uniqueTot);
    FenwickTree* sums = createTree(uniqueTot);

    // Updates both frequency and value-sum trees when window elements change.
    void addToTrees(int num, int freqDelta) {
        int compId = getCompressedId(uniqueNums, uniqueTot, num);
        long long weightedDelta = (long long)num * freqDelta;
        addVal(valFreqs, compId, freqDelta);
        addVal(sums, compId, weightedDelta);
    }

    // 7. Populate trees with the first window and record its equalization cost.
    for (int i = 0; i < subarrSz; i++) {
        addToTrees(nums[i], kFreqIncr);
    }
    wndwCosts[subarrSz - 1] = callWndwCost(valFreqs, sums, uniqueNums, uniqueTot, subarrSz);

    // 8. Slide the window across the array, updating trees and window costs.
    for (int i = subarrSz; i < numsSize; i++) {
        addToTrees(nums[i - subarrSz], kFreqDecr);
        addToTrees(nums[i], kFreqIncr);
        wndwCosts[i] = callWndwCost(valFreqs, sums, uniqueNums, uniqueTot, subarrSz);
    }

    freeTree(valFreqs);
    freeTree(sums);
    free(uniqueNums);
    return wndwCosts;
}

long long minOperations(int* nums, int numsSize, int subarrSz, int reqSubarrsTot) {
    // 1. Precompute minimum cost to equalize every contiguous window.
    long long* wndwCosts = calcWndwCosts(nums, numsSize, subarrSz);

    // 2. Allocate rolling DP tables for previous and current subarray counts.
    long long* currMinCosts = (long long*)calloc(numsSize + 1, sizeof(long long));
    long long* nextMinCosts = (long long*)malloc((numsSize + 1) * sizeof(long long));

    // 3. Iterate through the number of disjoint subarrays selected so far.
    for (int subarrCnt = 1; subarrCnt <= reqSubarrsTot; subarrCnt++) {
        for (int i = 0; i <= numsSize; i++) {
            nextMinCosts[i] = kInfinity;
        }

        int startIdx = subarrCnt * subarrSz;

        // 4. Transition DP by either skipping or picking the window at dpIdx.
        for (int dpIdx = startIdx; dpIdx <= numsSize; dpIdx++) {
            long long costIfSkipped = nextMinCosts[dpIdx - 1];
            long long costIfTaken = currMinCosts[dpIdx - subarrSz] + wndwCosts[dpIdx - 1];
            
            if (costIfTaken < costIfSkipped) {
                nextMinCosts[dpIdx] = costIfTaken;
            } else {
                nextMinCosts[dpIdx] = costIfSkipped;
            }
        }

        long long* temp = currMinCosts;
        currMinCosts = nextMinCosts;
        nextMinCosts = temp;
    }

    long long minCost = currMinCosts[numsSize];

    free(wndwCosts);
    free(currMinCosts);
    free(nextMinCosts);
    
    return minCost;
}