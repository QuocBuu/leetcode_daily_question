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
        diff[i] = abs(nums[i] - nums[i-1]);
        if (diff[i] <= maxDiff) {
            diff[i] = diff[i-1];
        }
        else {
            diff[i] = diff[i-1] + 1;
        }
    }

    for (int i = 0; i < queriesSize; i++) {
        ret[i] = (diff[queries[i][0]] == diff[queries[i][1]]);
    } 

    free(diff);
    return ret;
}