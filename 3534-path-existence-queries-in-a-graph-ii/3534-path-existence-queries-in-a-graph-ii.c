/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int val;
    int idx;
} node;

int cmp (const void* a, const void* b) {
    node* n1 = (node*)a;
    node* n2 = (node*)b;

    if (n1->val != n2-> val) {
        return n1->val - n2->val;
    }
    return n1->idx - n2->idx;
}

int* pathExistenceQueries(int n, int* nums, int numsSize, int maxDiff, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    #define LOG (18)
    node* nodeVec = malloc(sizeof(node) * n);
    for (int i = 0; i < n; i++) {
        nodeVec[i].val = nums[i];
        nodeVec[i].idx = i;
    }

    qsort(nodeVec, n, sizeof(node), cmp);

    int* sortArr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        sortArr[nodeVec[i].idx] = i;
    }

    int** logArr = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        logArr[i] = calloc(LOG, sizeof(int));
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        while ((nodeVec[i].val - nodeVec[k].val) > maxDiff) {
            logArr[k][0] = i - 1;
            k++;
        }
    }

    while (k < n) {
        logArr[k][0] = n - 1;
        k++;
    }

    for (int i = 1; i < LOG; i++) {
        for (int j = 0; j < n; j++) {
            logArr[j][i] = logArr[logArr[j][i - 1]][i - 1];
        }
    }

    int* ret = malloc(sizeof(int) * queriesSize);
    *returnSize = queriesSize;
    
    for (int i = 0; i < queriesSize; i++) {
        ret[i] = -1;

        int a = sortArr[queries[i][0]];
        int b = sortArr[queries[i][1]];

        if (a > b) {
            int val = a;
            a = b;
            b = val;
        }

        if (a == b) {
            ret[i] = 0;
            continue;
        }

        int cur = a;
        int step = 0;

        for (int i = LOG - 1; i >= 0; i--) {
            if (logArr[cur][i] < b) {
                step += 1 << i;
                cur = logArr[cur][i];
            }
        }

        if (logArr[cur][0] >= b) {
            ret[i] = step + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        free(logArr[i]);
    }
    free(logArr);
    free(sortArr);
    free(nodeVec);
    return ret;
}