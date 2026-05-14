int cmp (const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
bool isGood(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    if (nums[numsSize-1] != (numsSize-1) || nums[numsSize-2] != (numsSize-1)) {
        return false;
    }

    for (int i = 0; i < numsSize-2; i++) {
        if (nums[i] != i+1) {
            return false;
        }
    }

    return true;
}