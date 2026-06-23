#define MOD 1000000007
int zigZagArrays(int n, int l, int r) {
    int m = r - l + 1;
    long long *dp = malloc(m * sizeof(long long));
    long long *pref = malloc(m * sizeof(long long));
    long long *dp2 = malloc(m * sizeof(long long));

    for (int i = 0; i < m; i++) {
        dp[i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        pref[0] = dp[0];
        for (int j = 1; j < m; j++) {
            pref[j] = (pref[j - 1] + dp[j]) % MOD;
        }

        for (int j = 0; j < m; j++) {
            dp2[j] = 0;
        }

        if (i % 2 == 0) {
            for (int j = 1; j < m; j++) {
                dp2[j] = pref[j - 1];
            }
        } else {
            long long total = pref[m - 1];
            for (int j = 0; j < m - 1; j++) {
                dp2[j] = (total - pref[j] + MOD) % MOD;
            }
        }

        long long *temp = dp;
        dp = dp2;
        dp2 = temp;
    }

    long long ret = 0;

    for (int i = 0; i < m; i++) {
        ret = (ret + dp[i]) % MOD;
    }

    free(dp);
    free(dp2);
    free(pref);

    return (ret * 2) % MOD;
}