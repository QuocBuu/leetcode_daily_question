/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** createGrid(int m, int n, int* returnSize) {
    char** arr = malloc(sizeof(char*) * m);
    for (int i = 0; i < m; i++) {
        arr[i] = malloc(sizeof(char) * (n+1));
        memset(arr[i], '#', sizeof(char) * n);
        arr[i][n] = '\0';
    }

    memset(arr[0], '.', sizeof(char) * n);
    for (int i = 1; i < m; i++) {
        arr[i][n-1] = '.';
    }

    *returnSize = m;
    return arr;
}