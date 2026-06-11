void markLand (char** grid, int m, int n, int x, int y) {
    grid[x][y] = 'a';

    if (x > 0) {
        if (grid[x-1][y] == '1') {
            markLand(grid, m, n, x-1, y);
        }
    }
    if (x < m-1) {
        if (grid[x+1][y] == '1') {
            markLand(grid, m, n, x+1, y);
        }
    }

    if (y > 0) {
        if (grid[x][y-1] == '1') {
            markLand(grid, m, n, x, y-1);
        }
    }
    if (y < n-1) {
        if (grid[x][y+1] == '1') {
            markLand(grid, m, n, x, y+1);
        }
    }
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