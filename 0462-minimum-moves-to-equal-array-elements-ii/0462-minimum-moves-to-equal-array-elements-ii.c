int cmp (const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int minMoves2(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int val = 0;
    if (numsSize % 2) {
        val = nums[numsSize / 2];
    }
    else {
        val = (nums[numsSize/2 - 1] + nums[numsSize/2]) / 2;
    }

    int ret = 0;
    for (int i = 0; i < numsSize; i++) {
        ret += abs(val - nums[i]);
    }

    return ret;
}