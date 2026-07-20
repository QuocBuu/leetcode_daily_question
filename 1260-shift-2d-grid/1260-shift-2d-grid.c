/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes) {
    int m = gridSize;
    int n = gridColSize[0];
    int total = m * n;
    k %= m*n;

    int** ret = malloc(sizeof(int*) * m);
    *returnColumnSizes = malloc(sizeof(int) * m);
    *returnSize = m;
    for(int i = 0; i < m; i++) {
        ret[i] = malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
        for (int j = 0; j < n; j++) {
            int x = i * n + j;
            int y = (x - k + total) % total;
            
            x = y / n;
            y %= n;

            ret[i][j] = grid[x][y];
        }
    }

    return ret;
}