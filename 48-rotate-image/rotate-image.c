void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize/2;
    for (int k = 0; k < n; k++) {
        int last = matrixSize - 1 - k;
        for (int j = k; j < last; j++) {
            int offset = j - k;
            int temp = matrix[k][j];

            matrix[k][j] = matrix[last - offset][k];
            matrix[last - offset][k] = matrix[last][last - offset];
            matrix[last][last - offset] = matrix[j][last];
            matrix[j][last] = temp;
        }
    }
}