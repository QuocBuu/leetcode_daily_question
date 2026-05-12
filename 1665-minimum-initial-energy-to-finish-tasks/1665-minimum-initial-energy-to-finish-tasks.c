int cmp (const void* a, const void* b) {
    int* arr1 = *(int**)a;
    int* arr2 = *(int**)b;
    return (arr1[1] - arr1[0]) - (arr2[1] - arr2[0]);
}
int minimumEffort(int** tasks, int tasksSize, int* tasksColSize) {
    qsort(tasks, tasksSize, sizeof(int*), cmp);

    int ret = 0;
    for (int i = 0; i < tasksSize; i++) {
        // printf("%d\n", tasks[i][1]);
        if ((ret + tasks[i][0]) < tasks[i][1]) {
            ret = tasks[i][1];
        }
        else {
            ret += tasks[i][0];
        }
    }

    return ret;
}