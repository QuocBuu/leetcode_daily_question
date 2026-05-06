/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char** rotateTheBox(char** boxGrid, int boxGridSize, int* boxGridColSize, int* returnSize, int** returnColumnSizes) {
    int m = boxGridSize;
    int n = boxGridColSize[0];

    *returnSize = n;
    *returnColumnSizes = malloc(sizeof(int) * n);
    char ** ret = malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = m;
        ret[i] = malloc(sizeof(char) * m);
    }

    for (int i = 0; i < m; i++) {
        for (int j = n-1; j >= 0; j--) {
            if(boxGrid[i][j] == '#' && j != n-1) {
                int k = j;
                while(k < n-1) {
                    if (boxGrid[i][k+1] == '.') {
                        boxGrid[i][k+1] = '#';
                        boxGrid[i][k] = '.';
                        k++; 
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ret[j][(m-1)-i] = boxGrid[i][j];
        }
    }

    return ret;
}