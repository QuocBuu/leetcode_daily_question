int dp(int node, int m, int n, int* sumSuff, int** memo) {
    if (node + 2*m > n) {
        return sumSuff[node];
    }

    if (memo[node][m] != -1) {
        return memo[node][m];
    }

    int ret = INT_MAX;
    for (int x = 1; x <= (m * 2); x++) {
        int max = m > x ? m : x;
        int val = dp(node + x, max, n, sumSuff, memo);

        if (val < ret) {
            ret = val;
        }
    }

    memo[node][m] = sumSuff[node] - ret;
    return memo[node][m];
}

int stoneGameII(int* piles, int pilesSize) {
    int n = pilesSize;

    int* sumSuff = malloc(sizeof(int) * (n + 1));
    int** memo   = malloc(sizeof(int*) * n); 

    sumSuff[n] = 0;

    for (int i = n-1; i >= 0; i--) {
        sumSuff[i] = sumSuff[i+1] + piles[i];
    }

    for (int i = 0; i < n; i++) {
        memo[i] = malloc(sizeof(int) * n);
        memset(memo[i], -1, sizeof(int) * n);
    }

    int ret = dp(0, 1, n, sumSuff, memo);

    for (int i = 0; i < n; i++) {
        free(memo[i]);
    }

    free(sumSuff);
    free(memo);

    return ret;
}