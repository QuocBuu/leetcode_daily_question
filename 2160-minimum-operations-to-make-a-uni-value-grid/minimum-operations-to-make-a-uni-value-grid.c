int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
int minOperations(int** grid, int gridSize, int* gridColSize, int x) {
    int len = gridSize * gridColSize[0];
    int *array = malloc(sizeof(int)*len); 
    // Check 
    // if (array) {
    //     return -1;
    // }
    int k = 0;
    int diff = grid[0][0] % x;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] % x != diff) {
                free(array);
                return -1;
            }
            array[k++] = grid[i][j];
        }
    }

    qsort(array, len, sizeof(int), cmp);

    int equalValue = array[len/2];
    int ret = 0;
    for (int i = 0; i < len; i++) {
        ret += abs(array[i] - equalValue) / x;
    }

    free(array);

    return ret;
}