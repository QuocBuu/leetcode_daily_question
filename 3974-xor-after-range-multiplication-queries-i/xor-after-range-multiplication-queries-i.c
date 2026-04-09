#define MOD (1000000007)
int xorAfterQueries(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    for (int i = 0; i < queriesSize; i++) {
        for (int idx = queries[i][0]; idx <= queries[i][1]; idx += queries[i][2]) {
            nums[idx] = ((long long)nums[idx] * queries[i][3]) % MOD;
        }
    }

    int ret = nums[0];
    for (int i = 1; i < numsSize; i++) {
        ret ^= nums[i];
    }

    return ret;
}