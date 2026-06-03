/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructTransformedArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* ret = malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            ret[i] = nums[i]; 
        }
        else if (nums[i] > 0) {
            int val = (i + nums[i]) % numsSize;
            ret[i] = nums[val];
            // printf("%d - %d - %d\n", ret[i], nums[i], val);
        }
        else {
            int k = (abs(nums[i]) / numsSize) + 1;
            int val = (i + numsSize*k + nums[i]) % numsSize;
            // printf("%d  %d  %d %d\n", i, nums[i], numsSize, val);
            ret[i] = nums[val];
            // printf("%d - %d - %d\n", ret[i], nums[i], val);
        }
    }

    return ret;
}