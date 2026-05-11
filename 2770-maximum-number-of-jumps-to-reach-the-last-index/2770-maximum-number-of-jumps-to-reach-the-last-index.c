int maximumJumps(int* nums, int numsSize, int target) {
    int* array = malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        array[i] = -1;
    }

    array[0] = 0;
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i-1; j >= 0; j--) {
            long val = nums[i] - nums[j]; 
            if (((val + target) >= 0) && ((val - target) <= 0)) {
                if (array[j] > -1) {
                    if (array[j] + 1 > array[i]) {
                        array[i] = array[j] + 1;
                    }
                }
            } 
        }
    }

    int ret = array[numsSize - 1];
    free(array);
    return ret;
}