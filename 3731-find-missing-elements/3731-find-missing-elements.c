/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp (const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int* findMissingElements(int* nums, int numsSize, int* returnSize) {
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    int val = nums[numsSize - 1] - nums[0] - (numsSize - 1);
    // printf("val : %d\n", val);
    if (val == 0) {
        return NULL;
    }

    int* ret = malloc(sizeof(int) * val);
    for (int i = 0; i < numsSize - 1; i++) {
        int start = nums[i] + 1;
        // printf("start : %d\n", start);
        int end = nums[i + 1];
        // printf("end : %d\n", end);
        while (start != end) {
            ret[(*returnSize)++] = (start++);
        }
    }
    return ret;
}