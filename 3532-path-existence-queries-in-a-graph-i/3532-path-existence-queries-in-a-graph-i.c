/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* pathExistenceQueries(int n, int* nums, int numsSize, int maxDiff, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    bool *ret = malloc(sizeof(bool) * queriesSize);
    *returnSize = queriesSize;
    
    int *diff = malloc(sizeof(int) * n);
    diff[0] = 0;
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        diff[i] = nums[i] - nums[i-1];
        if (diff[i] <= maxDiff) {
            diff[i] = cnt;
        }
        else {
            cnt++;
            diff[i] = cnt;
        }
    }

    for (int i = 0; i < queriesSize; i++) {
        int A = diff[queries[i][0]];
        int B = diff[queries[i][1]];

        ret[i] = A == B ? true : false;
    } 

    free(diff);
    return ret;
}