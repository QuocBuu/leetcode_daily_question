bool stoneGame(int* piles, int pilesSize) {
    int* dp = malloc(sizeof(int) * pilesSize);

    // Len = 1;
    memcpy(dp, piles, sizeof(int) * pilesSize);

    for (int len = 2; len <= pilesSize; len++) {
        for (int i = 0; i <= (pilesSize - len); i++) {
            int j = i + len - 1;
            int left = piles[i] - dp[i+1];
            int right = piles[j] - dp[i];

            dp[i] = left > right ? left : right;
        }
    }

    bool ret = dp[0] > 0;

    free(dp);

    return ret;
}