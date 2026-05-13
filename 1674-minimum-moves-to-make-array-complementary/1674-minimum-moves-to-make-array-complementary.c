int minMoves(int* nums, int numsSize, int limit) {
    int halfSize = numsSize / 2;
    int *array = calloc(2 * limit + 2, sizeof(int));

    for (int i = 0; i < halfSize; i++) {
        int a = nums[i];
        int b = nums[numsSize - 1 - i];

        int mn = a < b ? a : b;
        int mx = a > b ? a : b;

        array[2] += 2;                    
        array[mn + 1]--; 
        array[mn + mx]--; 
        array[mn + mx + 1]++; 
        array[mx + limit + 1]++;
    }

    int ret = numsSize;
    int moves = 0;

    for (int sum = 2; sum <= 2 * limit; sum++) {
        moves += array[sum];
        if (moves < ret) {
            ret = moves;
        }
    }

    free(array);
    return ret;
}