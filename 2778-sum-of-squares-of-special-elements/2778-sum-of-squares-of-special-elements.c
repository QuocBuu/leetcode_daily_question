int sumOfSquares(int* nums, int numsSize) {    
    int ret = 0;
    for (int i = 0; i < numsSize; i++) {
        if (numsSize % (i+1)) {
            continue;
        }

        ret += nums[i] * nums[i];
        // printf("%d - %d\n", nums[i-1], ret);
    }

    return ret;    
}