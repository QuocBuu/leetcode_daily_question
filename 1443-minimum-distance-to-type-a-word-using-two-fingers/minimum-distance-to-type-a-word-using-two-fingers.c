int gerDistance(int p, int q) {
    int x1 = p / 6, y1 = p % 6;
    int x2 = q / 6, y2 = q % 6;
    return abs(x1 -x2) + abs(y1 - y2);
}
int minimumDistance(char* word) {
    int len = strlen(word);
    int ***arr = malloc(sizeof(int**) * len);
    for (int i = 0; i < len; i++) {
        arr[i] = malloc(sizeof(int*) * 26); // 'A' -> 'Z'
        for (int j = 0; j < 26; j++) {
            arr[i][j] = malloc(sizeof(int) * 26);
            for (int k = 0; k < 26; k++) {
                arr[i][j][k] = INT_MAX;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        arr[0][i][word[0] - 'A'] = 0;
        arr[0][word[0] - 'A'][i] = 0;
    }

    for (int i = 1; i < len; i++) {
        int cur = word[i] - 'A';
        int prev = word[i - 1] - 'A';
        int d =  gerDistance(prev, cur);

        for (int j = 0; j < 26; j++) {
            arr[i][cur][j] = fmin(arr[i][cur][j], arr[i-1][prev][j] + d);
            arr[i][j][cur] = fmin(arr[i][j][cur], arr[i-1][j][prev] + d);

            if (prev == j) {
                for (int k = 0; k < 26; k++) {
                    int d0 = gerDistance(k, cur);
                    arr[i][cur][j] = fmin(arr[i][cur][j], arr[i-1][k][j] + d0);
                    arr[i][j][cur] = fmin(arr[i][j][cur], arr[i-1][j][k] + d0);
                }
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (ans > arr[len-1][i][j]) {
                ans = arr[len-1][i][j];
            }
        }
    }

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 26; j++) {
            free(arr[i][j]);
        }
        free(arr[i]);
    }
    free(arr);

    return ans;
}