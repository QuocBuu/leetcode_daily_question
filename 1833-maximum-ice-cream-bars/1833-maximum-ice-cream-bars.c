int cmp (const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int maxIceCream(int* costs, int costsSize, int coins) {
    qsort(costs, costsSize, sizeof(int), cmp);

    int ret = 0;
    for (int i = 0; i< costsSize; i++) {
        if (coins < costs[i]) {
            return ret;
        }
        else {
            ret++;
            coins -= costs[i];
        }
    }
    return ret;    
}