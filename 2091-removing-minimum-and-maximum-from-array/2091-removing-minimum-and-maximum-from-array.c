int minimumDeletions(int* nums, int numsSize) {
    int max[2] = {nums[0], 0};
    int min[2] = {nums[0], 0};

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > max[0]) {
            max[0] = nums[i];
            max[1] = i;
        }

        if (nums[i] < min[0]) {
            min[0] = nums[i];
            min[1] = i;
        }
    }

    int leftMin = min[1] + 1;
    int leftMax = max[1] + 1;
    int rightMin = numsSize - min[1];
    int rightMax = numsSize - max[1];

    int ret = leftMin > leftMax ? leftMin : leftMax;
    int rightTotal = rightMin > rightMax ? rightMin : rightMax;
    if (ret > rightTotal) {
        ret = rightTotal;
    }

    int val1 = rightMin + leftMax;
    if (ret > val1) {
        ret = val1;
    }

    int val2 = rightMax + leftMin;
    if (ret > val2) {
        ret = val2;
    }

    return ret; 
}