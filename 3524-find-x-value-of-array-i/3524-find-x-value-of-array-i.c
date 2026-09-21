/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* resultArray(int* nums, int numsSize, int k, int* returnSize) {
    long long* res = calloc(k, sizeof(long long));
    int freq[5] = {0};

    for (int i = 0; i < numsSize; i++) {
        nums[i] %= k;

        int cur[5] = {0};
        cur[nums[i]]++;

        for (int x = 0; x < k; x++) {
            cur[(x * nums[i]) % k] += freq[x];
        }

        for (int x = 0; x < k; x++) {
            freq[x] = cur[x];
            res[x] += freq[x];
        }
    }

    *returnSize = k;
    return res;
}