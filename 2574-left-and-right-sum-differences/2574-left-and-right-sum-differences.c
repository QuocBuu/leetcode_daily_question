/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* leftRightDifference(int* nums, int numsSize, int* returnSize) {
    int sumRight = 0;
    for (int i = 0; i < numsSize; i++) {
        sumRight += nums[i];
    }
    *returnSize = numsSize;
    int* ret = malloc(sizeof(int) * numsSize);
    memset(ret, 0, sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        int val = 0;
        for (int j = i-1; j >= 0; j--) {
            val += nums[j];
        }
        // printf("%d - %d -%d\n", i, val, sumRight - nums[i]);
        val = (sumRight - nums[i] - 2*val);
        ret[i] = val > 0 ? val : -val;
    }

    return ret;
}