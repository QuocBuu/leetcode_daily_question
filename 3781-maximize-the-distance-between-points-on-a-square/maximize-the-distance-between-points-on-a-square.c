int cmp(const void* a, const void* b) {
    long long arg1 = *(const long long*)a;
    long long arg2 = *(const long long*)b;
    if (arg1 < arg2) {
        return -1;
    }
    if (arg1 > arg2) {
        return 1;
    }
    return 0;
}

int check(int n, long long* res, int resSize, int side, int k) {
    int* idx = (int*)malloc(k * sizeof(int));
    long long perimeter = (long long)side * 4;
    long long curr = res[0];
    idx[0] = 0;

    for (int i = 1; i < k; i++) {
        int l = 0, r = resSize;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (res[mid] < curr + n) 
                l = mid + 1;
            else r = mid;
        }
        if (l == resSize) {
            free(idx);
            return 0;
        }
        idx[i] = l;
        curr = res[l];
    }

    if (res[idx[k - 1]] - res[0] <= perimeter - n) {
        free(idx);
        return 1;
    }

    for (idx[0] = 1; idx[0] < idx[1]; idx[0]++) {
        for (int j = 1; j < k; j++) {
            while (idx[j] < resSize && res[idx[j]] < res[idx[j - 1]] + n) {
                idx[j]++;
            }
            if (idx[j] == resSize) {
                free(idx);
                return 0;
            }
        }
        if (res[idx[k - 1]] - res[idx[0]] <= perimeter - n) {
            free(idx);
            return 1;
        }
    }

    free(idx);
    return 0;
}

int maxDistance(int side, int** points, int pointsSize, int* pointsColSize, int k) {
    /* Make a hardmap */
    long long *res = (long long*) malloc(pointsSize * sizeof (long long));
    long long lSize = (long long) side;

    for (int i = 0; i < pointsSize; i++) {
        long long x = points[i][0];
        long long y = points[i][1];

        if (x == 0) {  /* (0,0) -> (0,size) */
            res[i] = y;
        }
        else if (y == lSize) {  /* (0,size) -> (size, size) */
            res[i] = lSize + x;
        }
        else if (x == lSize) {  /* (size,size) -> (size, 0) */
            res[i] = lSize*3 - y; 
        }
        else {
            res[i] = lSize*4 - x; /* (size,0) -> (0, 0) */
        }
    }

    qsort(res, pointsSize, sizeof(long long), cmp);

    int left = 1;
    int right = (int) ((lSize * 4) / k) + 1;

    while (left + 1 < right) {
        int mid = left + (right - left) /2;
        if (check(mid, res, pointsSize, side, k)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    return left;
}