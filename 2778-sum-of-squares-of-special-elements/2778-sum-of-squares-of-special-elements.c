int sumOfSquares(int* nums, int numsSize) {    
    int ret = 0;
    for (int i = 1; i <= numsSize; i++) {
        if (numsSize % i) {
            continue;
        }

        ret += nums[i-1] * nums[i-1];
        // printf("%d - %d\n", nums[i-1], ret);
    }

    return ret;    
}