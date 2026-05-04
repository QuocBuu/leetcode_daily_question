void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize/2;
    for (int k = 0; k < n; k++) {
        int last = matrixSize - 1 - k;
        for (int j = k; j < last; j++) {
            int offset = j - k;

            int x1 = k;
            int y1 = j;

            int x2 = j;
            int y2 = last;

            int x3 = last;
            int y3 = last - offset;

            int x4 = last - offset;
            int y4 = k;

            int temp = matrix[x1][y1];

            matrix[x1][y1] = matrix[x4][y4];
            matrix[x4][y4] = matrix[x3][y3];
            matrix[x3][y3] = matrix[x2][y2];
            matrix[x2][y2] = temp;
        }
    }
}