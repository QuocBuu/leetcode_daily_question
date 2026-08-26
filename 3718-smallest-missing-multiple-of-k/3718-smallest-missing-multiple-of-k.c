int cmp (const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int missingMultiple(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int val = k;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < val) {
            continue;
        }
        else if (nums[i] == val) {
            val += k;
        }
        else {
            return val;
        }
    }

    return val;
}