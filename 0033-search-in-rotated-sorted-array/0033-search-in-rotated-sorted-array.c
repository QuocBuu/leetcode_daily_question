int search(int* nums, int numsSize, int target) {
    int m = 0;
    int n = numsSize - 1;

    while (m <= n) {
        int k = n + ((m - n) / 2);
        if (nums[k] == target) {
            return k;
        }

        if (nums[k] >= nums[m]) {
            if (nums[m] <= target && nums[k] > target) {
                n = k - 1;
            }
            else {
                m = k + 1;
            }
        }
        else {
            if (nums[k] < target && nums[n] >= target) {
                m = k + 1;
            }
            else {
                n = k - 1;
            }
        }
    }

    return -1;
}