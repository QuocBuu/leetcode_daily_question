int cmp (const void *a, const void *b) {
    int *arrA = *(int**)a;
    int *arrB = *(int**)b;
    // printf("A - %d - %d\n", arrA[0], arrA[1]);
    // printf("B - %d - %d\n", arrB[0], arrB[1]);
    if (arrA[0] == arrB[0]) {
        return arrB[1] - arrA[1];
    }
    return arrA[0] - arrB[0];
}

int removeCoveredIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    int ret = intervalsSize;
    int k = INT_MIN;
    for (int i = 0; i < intervalsSize; i++) {
        // printf("%d - %d\n", intervals[i][0], intervals[i][1]);
        if (k < intervals[i][1]) {
            k = intervals[i][1];
        }
        else {
            ret--;
        }
    }
    return ret;
}