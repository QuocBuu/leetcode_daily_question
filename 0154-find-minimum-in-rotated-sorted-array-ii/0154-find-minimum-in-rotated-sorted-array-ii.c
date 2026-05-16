int findMin(int* nums, int numsSize) {
    if (nums[numsSize-1] > nums[0]) {
        return nums[0];
    }

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < nums[i-1]) {
            return nums[i];
        }
    }

    return nums[0];
}