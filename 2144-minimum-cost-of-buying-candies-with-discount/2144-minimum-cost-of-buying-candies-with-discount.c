int cmp (const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int minimumCost(int* cost, int costSize) {
    int ret = 0;
    int k = 0;
    qsort(cost, costSize, sizeof(int), cmp);
    for (int i = costSize - 1; i >= 0; i--) {
        if (k == 2) {
            k = 0;
        }
        else {
            k++;
            ret += cost[i];
        }
    }

    return ret;
}