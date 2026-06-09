// int cmp (const void* a, const void* b) {
//     return *(int*)a - *(int*)b;
// }
long long maxTotalValue(int* nums, int numsSize, int k) {
    if (numsSize <= 1) {
        return 0;
    }

    // qsort(nums, numsSize, sizeof(int), cmp);
    int max = INT_MIN;
    int min = INT_MAX;
    for (int i = 0; i < numsSize; i++) {
        if (max < nums[i]) {max = nums[i];}
        if (min > nums[i]) {min = nums[i];}
    }

    long long ret = (long long)(max - min) * k;

    return ret;
}