int maxConsistentColumns(int** grid, int gridSize, int* gridColSize, int limit) {
    int m = gridSize;
    int n = gridColSize[0];

    int* dp = malloc(sizeof(*dp) * n);
    int ret = 0;

    for (int i = 0; i < n; i++) {
        dp[i] = 1;

        for (int j = 0; j < i; j++) {
            bool valid = true;

            for (int k = 0; k < m; k++) {
                long long diff =
                    (long long)grid[k][i] - grid[k][j];

                if (diff > limit || diff < -limit) {
                    valid = false;
                    break;
                }
            }

            if (valid && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }

        if (ret < dp[i]) {
            ret = dp[i];
        }
    }

    free(dp);
    return ret;
}