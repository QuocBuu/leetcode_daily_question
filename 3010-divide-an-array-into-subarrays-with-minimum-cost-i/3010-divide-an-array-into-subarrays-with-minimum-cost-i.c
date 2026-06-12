int cmp (const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int minimumCost(int* nums, int numsSize) {
    int min = nums[0];
    qsort(nums+1, numsSize-1, sizeof(int), cmp);

    return min + nums[1] + nums[2];
}