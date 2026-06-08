/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
    int *ret = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    int coutLess = 0;
    int coutGrea = numsSize - 1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < pivot) {
            ret[coutLess] = nums[i];
            coutLess++;
        }

        if (nums[numsSize - 1 - i] > pivot) {
            ret[coutGrea] = nums[numsSize - 1 - i];
            coutGrea--;
        }
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == pivot) {
            ret[coutLess] = nums[i];
            coutLess++;
        }
    }

    return ret;
}