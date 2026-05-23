bool check(int* nums, int numsSize) {
    int val = 0;

    if (nums[0] < nums[numsSize - 1]) {
        val++;
    }

    for (int i = 1; i < numsSize; i++) {
        if (nums[i - 1] > nums[i]) {
            val++;
        }
    }

    return val <= 1;
}