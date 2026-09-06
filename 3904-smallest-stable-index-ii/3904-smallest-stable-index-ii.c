int firstStableIndex(int* nums, int numsSize, int k) {
    int* arrRight = malloc(sizeof(int) * numsSize);
    int* arrLeft  = malloc(sizeof(int) * numsSize);
    int min = INT_MAX;
    int max = INT_MIN;

    for (int i = 0; i < numsSize; i++) {
        // LEFT
        if (max < nums[i]) {
            max = nums[i];
        }
        arrLeft[i] = max;

        int j = numsSize - 1 - i;
        if (min > nums[j]) {
            min = nums[j];
        }
        arrRight[j] = min;
    }

    for (int i = 0; i < numsSize; i++) {
        if (arrLeft[i] - arrRight[i] <= k) {
            free(arrLeft);
            free(arrRight);
            return i;
        }
    }
    
    free(arrLeft);
    free(arrRight);
    return -1;
}