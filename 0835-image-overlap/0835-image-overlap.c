int largestOverlap(int** img1, int img1Size, int* img1ColSize, int** img2, int img2Size, int* img2ColSize) {
    int** node1 = malloc(sizeof(int*) * img1Size * img1Size);
    int** node2 = malloc(sizeof(int*) * img1Size * img1Size);
    int cnt1 = 0;
    int cnt2 = 0;

    for (int i = 0; i < img1Size; i++) {
        for (int j = 0; j < img1Size; j++) {
            if (img1[i][j] == 1) {
                node1[cnt1] = malloc(sizeof(int) * 2);
                node1[cnt1][0] = i;
                node1[cnt1][1] = j;
                cnt1++;
            }

            if (img2[i][j] == 1) {
                node2[cnt2] = malloc(sizeof(int) * 2);
                node2[cnt2][0] = i;
                node2[cnt2][1] = j;
                cnt2++;
            }
        }
    }

    int ret = 0;
    int hashmap[60][60] = {0};
    for (int i = 0; i < cnt1; i++) {
        int x1 = node1[i][0];
        int y1 = node1[i][1];
        for (int j = 0; j < cnt2; j++) {
            int x2 = node2[j][0];
            int y2 = node2[j][1];
            int dx = x1 - x2 + img1Size;
            int dy = y1 - y2 + img1Size;

            hashmap[dx][dy]++;
            if (hashmap[dx][dy] > ret) {
                ret = hashmap[dx][dy];
            }
        }
        free(node1[i]);
    }

    for (int i = 0; i < cnt2; i++) {
        free(node2[i]);
    }

    free(node1);
    free(node2);

    return ret;
}