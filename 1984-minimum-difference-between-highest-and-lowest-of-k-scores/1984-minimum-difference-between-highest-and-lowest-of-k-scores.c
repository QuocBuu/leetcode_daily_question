int cmp (const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int minimumDifference(int* nums, int numsSize, int k) {
    if (numsSize <= 1) {
        return 0;
    }

    qsort(nums, numsSize, sizeof(int), cmp);
    int min = INT_MAX;
    for (int i = 0; i+k-1 < numsSize; i++) {
        int val = nums[i+k-1] - nums[i];
        if (val < min) {
            min = val;
        } 
    }

    return min;
}