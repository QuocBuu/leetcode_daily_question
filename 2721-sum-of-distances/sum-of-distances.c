/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MOD 1000000007 /* 1,000,000,007 */
#define HTMOD 100000049 /* 100,000,049 */

enum {VAL,INDEX,NEXT};
#define ESIZE 3

void insertht(int *ht, int htSize, int (*nodes)[ESIZE], int node);
int hash(int n, int size);

long long* distance(int* nums, int numsSize, int* returnSize) {
    int n = numsSize, htSize = (n << 1) + 1, ht[htSize];
    int nodes[n+1][ESIZE];
    memset(ht, -1, sizeof(ht));
    for (int node = 0; node < n; ++node) {
        nodes[node][VAL] = nums[node];
        nodes[node][INDEX] = node;
        insertht(ht, htSize, nodes, node);
    }
    long long *ans = (long long *) malloc(n * sizeof(long long));
    memset(ans, -1, n * sizeof(long long));
    int arr[n];
    for (int i = 0; i < n; ++i) {
        if (ans[i] < 0) {
            int e = n, sz = 0;
            int node = ht[hash(nums[i], htSize)];
            while (node >= 0) {
                if (nodes[node][VAL] == nums[i]) {
                    int j = nodes[node][INDEX];
                    arr[--e] = j;
                    ++sz;
                }
                node = nodes[node][NEXT];
            }
            int *indexes = &arr[e];
            long long prefSum[sz+1];
            prefSum[0] = 0;
            for (int j = 0; j < sz; ++j) {
                prefSum[j+1] = prefSum[j] + indexes[j];
            }
            for (int j = 0; j < sz; ++j) {
                long long k = indexes[j];
                long long val = k * j - prefSum[j];
                val += (prefSum[sz] - prefSum[j+1]);
                val -= k * (sz - j - 1);
                ans[k] = val;
            }
        }
    }
    *returnSize = n;
    return ans;
}

int hash(int n, int size) {
    long long h;
    h = ((long long) n + MOD) % HTMOD;
    return h % size;
}

void insertht(int *ht, int htSize, int (*nodes)[ESIZE], int node) {
    int index = hash(nodes[node][VAL], htSize);
    nodes[node][NEXT] = ht[index];
    ht[index] = node;
}