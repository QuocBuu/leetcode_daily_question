

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pathsWithMaxScore(char ** board, int boardSize, int* returnSize){
    #define MOD (1000000007)

    int n = boardSize;

    int *score = malloc(sizeof(int) * (n + 1));
    int *ways  = malloc(sizeof(int) * (n + 1));

    memset(score, -1, sizeof(int) * (n + 1));
    memset(ways,   0, sizeof(int) * (n + 1));

    for (int i = n - 1; i >= 0; i--) {
        int *newScore = malloc(sizeof(int) * (n + 1));
        int *newWays  = malloc(sizeof(int) * (n + 1));

        memset(newScore, -1, sizeof(int) * (n + 1));
        memset(newWays,   0, sizeof(int) * (n + 1));

        for (int j = n - 1; j >= 0; j--) {
            char c = board[i][j]; 
            if (c == 'X') {
                continue;
            }

            if (c == 'S') {
                newScore[j] = 0;
                newWays[j]  = 1;
                continue;
            }

            int best = score[j];
            if (newScore[j + 1] > best) {
                best = newScore[j + 1];
            }

            if (score[j + 1] > best) {
                best = score[j + 1];
            }

            if (best == -1) {
                continue;
            }

            long long cout = 0;
            if (score[j] == best) {
                cout += ways[j];
            }

            if (newScore[j + 1] == best) {
                cout += newWays[j + 1];
            }

            if (score[j + 1] == best) {
                cout += ways[j + 1];
            }

            int val = board[i][j] == 'E' ? 0 : board[i][j] - '0'; 
            newScore[j] = best + val;
            newWays[j]  = cout % MOD;
        }

        free(score);
        free(ways);

        score = newScore;
        ways  = newWays;
    }

    int *ret = malloc(2 * sizeof(int));
    *returnSize = 2;

    if (score[0] == -1) {
        ret[0] = 0;
        ret[1] = 0;
    }
    else {
        ret[0] = score[0];
        ret[1] = ways[0];
    }

    free(score);
    free(ways);

    return ret;
}