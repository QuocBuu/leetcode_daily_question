int** rotateGrid(int** grid, int gridSize, int* gridColSize, int k,
                 int* returnSize, int** returnColumnSizes) {
    int m = gridSize;
    int n = gridColSize[0];

    *returnSize = m;
    *returnColumnSizes = malloc(sizeof(int) * m);

    int** ret = malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;
        ret[i] = malloc(sizeof(int) * n);
        memcpy(ret[i], grid[i], sizeof(int) * n);
    }

    int* buffer = malloc(sizeof(int) * m * n);
    int layers = (m < n ? m : n) / 2;

    for (int layer = 0; layer < layers; layer++) {
        int top = layer;
        int left = layer;
        int bottom = m - layer - 1;
        int right = n - layer - 1;

        int index = 0;

        for (int col = left; col <= right; col++)
            buffer[index++] = grid[top][col];

        for (int row = top + 1; row <= bottom; row++)
            buffer[index++] = grid[row][right];

        for (int col = right - 1; col >= left; col--)
            buffer[index++] = grid[bottom][col];

        for (int row = bottom - 1; row > top; row--)
            buffer[index++] = grid[row][left];

        int len = index;
        int rotate = k % len;

        index = 0;

        for (int col = left; col <= right; col++) {
            ret[top][col] = buffer[(index + rotate) % len];
            index++;
        }

        for (int row = top + 1; row <= bottom; row++) {
            ret[row][right] = buffer[(index + rotate) % len];
            index++;
        }

        for (int col = right - 1; col >= left; col--) {
            ret[bottom][col] = buffer[(index + rotate) % len];
            index++;
        }

        for (int row = bottom - 1; row > top; row--) {
            ret[row][left] = buffer[(index + rotate) % len];
            index++;
        }
    }

    free(buffer);
    return ret;
}