int cmp (const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int minimizeSum(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int a = nums[numsSize - 1] - nums[2];
    int b = nums[numsSize - 2] - nums[1];
    int c = nums[numsSize - 3] - nums[0];
    
    a = a < b ? a : b;
    a = a < c ? a : c;
    return a;
}