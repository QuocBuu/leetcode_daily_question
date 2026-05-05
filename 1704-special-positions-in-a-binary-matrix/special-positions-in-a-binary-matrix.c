int numSpecial(int** mat, int matSize, int* matColSize) {
    int m = matSize;
    int n = matColSize[0];

    int arrayI[100] = {0};
    int arrayJ[100] = {0};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                arrayI[i]++;
                arrayJ[j]++;
            }
        }
    }

    int ret = 0;

    for (int i = 0; i < m; i++) {
        if (arrayI[i] != 1) {
            continue;
        }

        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                if (arrayJ[j] == 1) {
                    ret++;
                }
                break;
            }
        }
    }
    return ret;
}