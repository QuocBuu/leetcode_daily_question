int cmp (const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
long long maxTotalValue(int* nums, int numsSize, int k) {
    if (numsSize <= 1) {
        return 0;
    }

    qsort(nums, numsSize, sizeof(int), cmp);

    long long ret = (long long)(nums[numsSize-1] - nums[0]) * k;

    return ret;
}