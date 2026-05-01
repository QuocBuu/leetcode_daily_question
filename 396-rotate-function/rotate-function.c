int maxRotateFunction(int* nums, int numsSize) {
    long sum = 0;
    long R = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        R += (long)i * nums[i];
    }

    long maxVal = R;

    for (int k = 1; k < numsSize; k++) {
        R = R + sum - (long)numsSize * nums[numsSize - k];
        if (R > maxVal) {
            maxVal = R;
        }
    }

    return (int)maxVal;
}