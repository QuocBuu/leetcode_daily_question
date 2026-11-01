int minMoves(int* nums, int numsSize) {
    int min = nums[0];
    int ret = 0;
    for (int i = 0; i < numsSize; i++) {
        if (min > nums[i]) {
            min = nums[i];
        }
        ret += nums[i];
    }
    return ret - min * numsSize;
}