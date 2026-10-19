/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp (const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int* targetIndices(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    if (nums[0] > target || nums[numsSize - 1] < target) {
        return NULL;
    }

    int* ret = malloc(sizeof(int) * (numsSize));

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            ret[(*returnSize)++] = i;
        }
    }

    if (*returnSize == 0) {
        free(ret);
        return NULL;
    }

    return ret;
}