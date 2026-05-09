/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** rotateGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes){
    int rows = gridSize;
    int cols = gridColSize[0];
    int layers = (rows < cols ? rows : cols) >> 1;

    int** retval = (int**)malloc(sizeof(int*) * rows);
    *returnColumnSizes = (int*)malloc(sizeof(int) * rows);

    for (int i = 0; i < rows; i++)
    {
        retval[i] = (int*)malloc(sizeof(int) * cols);
        (*returnColumnSizes)[i] = cols;

        memcpy(retval[i], grid[i], sizeof(int) * cols);
    }

    int buffer[200];

    for (int layer = 0; layer < layers; layer++)
    {
        int top = layer;
        int left = layer;
        int bottom = rows - layer - 1;
        int right = cols - layer - 1;

        int idx = 0;

        for (int c = left; c <= right; c++)
        {
            buffer[idx++] = grid[top][c];
        }

        for (int r = top + 1; r <= bottom - 1; r++)
        {
            buffer[idx++] = grid[r][right];
        }

        for (int c = right; c >= left; c--)
        {
            buffer[idx++] = grid[bottom][c];
        }

        for (int r = bottom - 1; r >= top + 1; r--)
        {
            buffer[idx++] = grid[r][left];
        }

        int len = idx;
        int shift = k % len;

        idx = 0;

        for (int c = left; c <= right; c++)
        {
            retval[top][c] = buffer[(idx + shift) % len];
            idx++;
        }

        for (int r = top + 1; r <= bottom - 1; r++)
        {
            retval[r][right] = buffer[(idx + shift) % len];
            idx++;
        }

        for (int c = right; c >= left; c--)
        {
            retval[bottom][c] = buffer[(idx + shift) % len];
            idx++;
        }

        for (int r = bottom - 1; r >= top + 1; r--)
        {
            retval[r][left] = buffer[(idx + shift) % len];
            idx++;
        }
    }

    *returnSize = rows;

    return retval;
}