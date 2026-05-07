/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxValue(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int *ret = malloc(sizeof(int) * numsSize);

    ret[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        ret[i] = ret[i-1] > nums[i] ? ret[i-1] : nums[i]; 
    }

    int k = numsSize - 1;
    for (int i = numsSize - 2; i >= 0; i--) {
        if (ret[i] > nums[k]) {
            ret[i] = ret[k];
        }
        if (nums[i] < nums[k]) {
            k = i;
        }
    }

    return ret;
}