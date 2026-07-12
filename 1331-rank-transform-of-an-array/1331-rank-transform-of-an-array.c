/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp (const void* a, const void* b) {
    int* markA = *(int**)a;
    int* markB = *(int**)b;

    if (markA[0] > markB[0]) {
        return 1;
    }

    if (markA[0] < markB[0]) {
        return -1;
    }

    return 0;
}

int* arrayRankTransform(int* arr, int arrSize, int* returnSize) {
    int** mark = malloc(sizeof(int*) * arrSize);
    
    for (int i = 0; i < arrSize; i++) {
        mark[i] = malloc(sizeof(int) * 2);
        mark[i][0] = arr[i];
        mark[i][1] = i; 
    }

    qsort(mark, arrSize, sizeof(int*), cmp);

    int* ret = malloc(sizeof(int) * arrSize);
    *returnSize = arrSize;
    int k = 0;
    int val = INT_MIN;
    for (int i = 0; i < arrSize; i++) {
        if (val != mark[i][0]) {
            k++;
            val = mark[i][0];
        }
        ret[mark[i][1]] = k;
        free(mark[i]);
    }

    free(mark);

    return ret;
}