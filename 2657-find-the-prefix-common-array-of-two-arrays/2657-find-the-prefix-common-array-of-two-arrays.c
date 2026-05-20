/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
    int *ret = malloc(ASize*sizeof(int));
    int *array = malloc((ASize+1)*sizeof(int));
    memset(array, 0, (ASize+1)*sizeof(int));
    int count = 0;

    for (int i = 0; i < ASize; i++) {
        array[A[i]]++;
        array[B[i]]++;
        if (A[i] == B[i]) {
            count++;
        }
        else {
            if (array[A[i]] == 2) {
                count++;
            }
            if (array[B[i]] == 2) {
                count++;
            }
        }

        ret[i] = count;
    }

    *returnSize = ASize;
    return ret;
}