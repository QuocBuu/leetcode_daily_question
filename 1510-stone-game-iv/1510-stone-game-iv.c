bool winnerSquareGame(int n) {
    bool* dp = malloc(sizeof(bool) * (n + 1));
    memset(dp, 0, sizeof(bool) * (n + 1));
    for (int i = 0; i < n; i++) {
        if (dp[i]) {
            continue;
        }
        
        for (int j = 1;  i + j * j <= n; j++) {
            dp[i + j*j] = true;
        }
    }

    bool ret = dp[n]; 
    free(dp);
    return ret;
}