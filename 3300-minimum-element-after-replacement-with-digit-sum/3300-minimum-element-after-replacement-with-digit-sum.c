#pragma GCC optimize("Os")
int minElement(int* nums, int numsSize) {
    int ret = INT_MAX;
    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];
        nums[i] = 0;
        while (val) {
            nums[i] += val % 10;
            val /= 10;
        }

        if (nums[i] < ret) {
            ret = nums[i];
        }
    }

    return ret;
}