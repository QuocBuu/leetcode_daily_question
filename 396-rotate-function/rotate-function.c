int maxRotateFunction(int* nums, int numsSize) {
    int sum = 0;
    int R = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        R += (int)i * nums[i];
    }

    int maxVal = R;

    for (int k = 1; k < numsSize; k++) {
        R = R + sum - (int)numsSize * nums[numsSize - k];
        if (R > maxVal) {
            maxVal = R;
        }
    }

    return (int)maxVal;
}