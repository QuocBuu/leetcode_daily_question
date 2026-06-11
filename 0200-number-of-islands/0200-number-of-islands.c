void markLand(char** grid, int m, int n, int x, int y) {
    if (x < 0 || y < 0 || x >= m || y >= n) {
        return;
    }

    if (grid[x][y] != '1') {
        return;
    }

    grid[x][y] = 'a';

    markLand(grid, m, n, x - 1, y);

    markLand(grid, m, n, x + 1, y);

    markLand(grid, m, n, x, y - 1);

    markLand(grid, m, n, x, y + 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int max = 0;
    int m = gridSize;
    int n = gridColSize[0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                max++;
                markLand(grid, m, n, i, j);
            }
        }
    }

    return max;
}