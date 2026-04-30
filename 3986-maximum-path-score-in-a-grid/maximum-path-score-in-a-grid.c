int maxPathScore(int** grid, int gridSize, int* gridColSize, int k) {
    int n = gridSize == 0 ? 0 : gridColSize[0];

    int*** dp = (int***)malloc(gridSize * sizeof(int**));
    for (int i = 0; i < gridSize; i++) {
        dp[i] = (int**)malloc(n * sizeof(int*));
        for (int j = 0; j < n; j++) {
            dp[i][j] = (int*)malloc((k + 1) * sizeof(int));
            for (int c = 0; c <= k; c++) {
                dp[i][j][c] = INT_MIN;
            }
        }
    }

    dp[0][0][0] = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < n; j++) {
            for (int c = 0; c <= k; c++) {
                if (dp[i][j][c] == INT_MIN) {
                    continue;
                }

                if (i + 1 < gridSize) {
                    int val = grid[i + 1][j];
                    int cost = val == 0 ? 0 : 1;
                    if (c + cost <= k) {
                        int* target = &dp[i + 1][j][c + cost];
                        if (*target < dp[i][j][c] + val) {
                            *target = dp[i][j][c] + val;
                        }
                    }
                }

                if (j + 1 < n) {
                    int val = grid[i][j + 1];
                    int cost = val == 0 ? 0 : 1;
                    if (c + cost <= k) {
                        int* target = &dp[i][j + 1][c + cost];
                        if (*target < dp[i][j][c] + val) {
                            *target = dp[i][j][c] + val;
                        }
                    }
                }
            }
        }
    }

    int ans = INT_MIN;
    for (int c = 0; c <= k; c++) {
        if (dp[gridSize - 1][n - 1][c] > ans) {
            ans = dp[gridSize - 1][n - 1][c];
        }
    }

    return ans < 0 ? -1 : ans;
}