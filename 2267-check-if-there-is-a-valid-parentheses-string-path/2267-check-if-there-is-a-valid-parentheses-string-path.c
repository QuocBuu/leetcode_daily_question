int m = 0;
int n = 0;

bool dp(char** grid, int x, int y, int k, int*** hardMap) {
    if (x == m || y == n) {
        return 0;
    }

    if (grid[x][y] == '(') {
        k++;
    }
    else {
        k--;
    }

    if (k < 0) {
        return 0;
    }

    if (x == (m - 1) && y == (n - 1)) {
        return k == 0;
    }

    if (hardMap[x][y][k] != -1) {
        return hardMap[x][y][k];
    }

    bool ret = dp(grid, x + 1, y, k, hardMap) | dp(grid, x, y + 1, k, hardMap);
    hardMap[x][y][k] = ret;
    return ret;
}

bool hasValidPath(char** grid, int gridSize, int* gridColSize) {
    m = gridSize;
    n = gridColSize[0];
    int max = m + n + 1;
    // printf("m: %d - n: %d\n", m, n);
    
    int*** hardMap = malloc(sizeof(int**) * m);
    for (int i = 0; i < m; i++) {
        hardMap[i] = malloc(sizeof(int*) * n);
        for (int j = 0; j < n; j++) {
            hardMap[i][j] = malloc(sizeof(int) * max);
            memset(hardMap[i][j], -1, sizeof(int) * max);
            // printf("%d - %d\n", i, j);
        }
    }

    bool ret = dp(grid, 0, 0, 0, hardMap);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            free(hardMap[i][j]);
        }
        free(hardMap[i]);
    }
    free(hardMap);

    return ret;
}