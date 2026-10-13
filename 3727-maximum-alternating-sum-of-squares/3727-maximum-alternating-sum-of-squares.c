int cmp(const void* a, const void* b) {
    return abs(*(int*)a) - abs(*(int*)b);
}

long long maxAlternatingSum(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int right = numsSize - 1;
    int left = 0;
    int cnt = 0;
    long long ret = 0;
    while (left <= right) {
        if (cnt % 2) {
            // printf("%d \n", nums[left]);
            ret -= (long long)nums[left] * nums[left];
            left++;
            cnt++;
        }
        else {
            ret += (long long)nums[right] * nums[right];
            right--;
            cnt++;
        }
    }

    return ret;    
}