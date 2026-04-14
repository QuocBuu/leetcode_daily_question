#include <stdlib.h>

typedef struct {
    long long val;
    int idx;
} Pair;

int cmp_robot(const void* a, const void* b) {
    int valA = *(const int*)a;
    int valB = *(const int*)b;
    if (valA < valB) {
        return -1;
    } else if (valA > valB) {
        return 1;
    }
    return 0;
}

int cmp_factory(const void* a, const void* b) {
    int* factA = *(int**)a;
    int* factB = *(int**)b;
    if (factA[0] < factB[0]) {
        return -1;
    } else if (factA[0] > factB[0]) {
        return 1;
    }
    return 0;
}

long long minimumTotalDistance(int* robot, int robotSize, int** factory, int factorySize, int* factoryColSize) {
    int n = robotSize;
    int m = factorySize;
    qsort (robot, n, sizeof(int), cmp_robot);
    qsort (factory, m, sizeof(int*), cmp_factory);

    long long MAX = LLONG_MAX;

    long long b0[105];
    long long b1[105];
    long long b2[105];
    Pair q[105];

    for (int i = 1; i <= n; i++) {
        b0[i] = MAX;
    }
    b0[0] = 0;

    for (int i = 0; i < m; i++) {
        if (factory[i][1] == 0) {
            continue;
        }

        long long fpos = factory[i][0];
        int limit = factory[i][1];

        b2[0] = 0;

        for (int j = 0; j < n; j++) {
            long long diff = (long long) robot[j] - fpos;
            if (diff < 0) {
                diff = -diff;
            }
            b2[j+1] = b2[j] + diff;
        }

        int head = 0;
        int tail = 0;

        q[tail].val = b0[0];
        q[tail].idx = 0;
        tail++;

        for (int k = 1; k <= n; k ++) {
            if (head < tail && q[head].idx < k - limit) {
                head++;
            }

            b1[k] = b0[k];

            if (head < tail) {
                long long val = q[head].val + b2[k];
                if (val < b1[k]) {
                    b1[k] = val;
                }
            }

            if (b0[k] != MAX) {
                long long target = b0[k] - b2[k];
                while (head < tail && q[tail - 1].val >= target) {
                    tail--;
                }
                q[tail].val = target;
                q[tail].idx = k;
                tail++;
            }
        }
        
        for (int k = 1; k <= n; k++) {
            b0[k] = b1[k];
        }
    }

    return b0[n];
}