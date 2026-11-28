int cmp(const void* a, const void* b) {
    const int* itemA = *(const int**)a;
    const int* itemB = *(const int**)b;
    return (itemA[1] > itemB[1]) - (itemA[1] < itemB[1]);
}

int maximumSaleItems(int** items, int itemsSize, int* itemsColSize,
                     int budget) {
    qsort(items, itemsSize, sizeof(int*), cmp);
    int mx = 0;
    for (int i = 0; i < itemsSize; i++) {
        if (items[i][0] > mx) {
            mx = items[i][0];
        }
    }
    int* freq = (int*)calloc(mx + 1, sizeof(int));
    for (int i = 0; i < itemsSize; i++) {
        freq[items[i][0]]++;
    }
    for (int i = 1; i <= mx; i++) {
        if (freq[i] > 0) {
            for (int j = i * 2; j <= mx; j += i) {
                freq[i] += freq[j];
            }
        }
    }

    int mn = items[0][1];
    int ans = 0;
    for (int i = 0; i < itemsSize; i++) {
        int factor = items[i][0], price = items[i][1];
        if (price - mn > mn) {
            break;
        }
        int cnt = freq[factor] - 1;
        int take = budget / price;
        if (cnt < take) {
            take = cnt;
        }
        ans += take * 2;
        budget -= take * price;
    }
    ans += budget / mn;
    free(freq);
    return ans;
}