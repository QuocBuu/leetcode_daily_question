#define MAXN 105

long long maximumScore(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;

    if (n == 1)
    {
        return 0;
    }

    long long colSum[MAXN][MAXN];
    memset(colSum, 0, sizeof(colSum));

    for (int c = 0; c < n; c++)
    {
        for (int r = 1; r <= n; r++)
        {
            colSum[c][r] = colSum[c][r - 1] + grid[r - 1][c];
        }
    }

    static long long dp[MAXN][MAXN][MAXN];
    static long long prevMax[MAXN][MAXN];
    static long long prevSuffixMax[MAXN][MAXN];

    memset(dp, 0, sizeof(dp));
    memset(prevMax, 0, sizeof(prevMax));
    memset(prevSuffixMax, 0, sizeof(prevSuffixMax));

    for (int i = 1; i < n; i++)
    {

        for (int currH = 0; currH <= n; currH++)
        {
            for (int prevH = 0; prevH <= n; prevH++)
            {
                long long best = 0;

                if (currH <= prevH)
                {
                    long long extraScore =
                        colSum[i][prevH] - colSum[i][currH];

                    long long candidate =
                        prevSuffixMax[prevH][0] + extraScore;

                    best = candidate;
                }
                else
                {
                    long long extraScore =
                        colSum[i - 1][currH] - colSum[i - 1][prevH];

                    long long candidate1 =
                        prevSuffixMax[prevH][currH];

                    long long candidate2 =
                        prevMax[prevH][currH] + extraScore;

                    best = candidate1 > candidate2 ? candidate1 : candidate2;
                }

                dp[i][currH][prevH] = best;
            }
        }


        for (int currH = 0; currH <= n; currH++)
        {
            prevMax[currH][0] = dp[i][currH][0];

            for (int prevH = 1; prevH <= n; prevH++)
            {
                long long penalty = 0;

                if (prevH > currH)
                {
                    penalty =
                        colSum[i][prevH] - colSum[i][currH];
                }

                long long val =
                    dp[i][currH][prevH] - penalty;

                prevMax[currH][prevH] =
                    prevMax[currH][prevH - 1] > val
                        ? prevMax[currH][prevH - 1]
                        : val;
            }

            prevSuffixMax[currH][n] = dp[i][currH][n];

            for (int prevH = n - 1; prevH >= 0; prevH--)
            {
                long long a = prevSuffixMax[currH][prevH + 1];
                long long b = dp[i][currH][prevH];

                prevSuffixMax[currH][prevH] = a > b ? a : b;
            }
        }
    }

    long long ans = 0;

    for (int k = 0; k <= n; k++)
    {
        long long a = dp[n - 1][n][k];
        long long b = dp[n - 1][0][k];

        long long best = a > b ? a : b;

        if (best > ans)
        {
            ans = best;
        }
    }

    return ans;
}