int cmp(const void *a, const void *b) {
    int *arr1 = *(int **)a;
    int *arr2 = *(int **)b;

    return arr1[0] - arr2[0];
}

int maxBuilding(int n, int **restrictions, int restrictionsSize,
                int *restrictionsColSize) {
    int *start = malloc(2 * sizeof(int));
    int *end = malloc(2 * sizeof(int));

    start[0] = 1;
    start[1] = 0;

    end[0] = n;
    end[1] = n - 1;

    int size = restrictionsSize + 2;

    int **res = malloc(size * sizeof(int *));

    for (int i = 0; i < restrictionsSize; i++) {
        res[i] = restrictions[i];
    }

    res[restrictionsSize] = start;
    res[restrictionsSize + 1] = end;

    qsort(res, size, sizeof(int *), cmp);

    /* Right -> Left */
    for (int i = size - 2; i >= 0; i--) {
        int limit =
            res[i + 1][1] + (res[i + 1][0] - res[i][0]);

        if (res[i][1] > limit) {
            res[i][1] = limit;
        }
    }

    int ans = 0;

    /* Left -> Right */
    for (int i = 1; i < size; i++) {
        int limit =
            res[i - 1][1] + (res[i][0] - res[i - 1][0]);

        if (res[i][1] > limit) {
            res[i][1] = limit;
        }

        int dist = res[i][0] - res[i - 1][0];

        int peak =
            (res[i - 1][1] + res[i][1] + dist) / 2;

        if (peak > ans) {
            ans = peak;
        }
    }

    free(start);
    free(end);
    free(res);

    return ans;
}