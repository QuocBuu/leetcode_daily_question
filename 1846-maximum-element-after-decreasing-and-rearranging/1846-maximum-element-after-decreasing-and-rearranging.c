int cmp (const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
int maximumElementAfterDecrementingAndRearranging(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), cmp);

    arr[0] = 1;
    int ret = 1;
    for (int i = 1; i < arrSize; i++) {
        int val = arr[i-1] + 1;
        if (arr[i] > val) {
            arr[i] = val;
        }

        if (arr[i] > ret) {
            ret = arr[i];
        }
    }

    return ret;
}