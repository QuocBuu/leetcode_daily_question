void update(long long* cnt, long long* total, int n, int p) {
    for (int i = n - p; i <= n; i += i & -i) {
        cnt[i]++;
        total[i] += p;
    }
}

void query(long long* cnt, long long* total, int n, int p, long long* c, long long* s) {
    *c = 0;
    *s = 0;
    for (int i = n - p - 1; i > 0; i -= i & -i) {
        *c += cnt[i];
        *s += total[i];
    }
}

int sumCounts(int* nums, int numsSize) {
    #define MOD (1000000007)
    int n = numsSize;
    long long ret = 0;

    long long* cnt = calloc(n + 1, sizeof(long long));
    long long* total = calloc(n + 1, sizeof(long long));
    int* last = calloc(100001, sizeof(int));

    for (int r = 0; r < n; r++) {
        int p = last[nums[r]] - 1;

        long long c = 0;
        long long s = 0;
        query(cnt, total, n, p, &c, &s);

        long long gain = (long long)(r - p) * (r - p) - 2 * (s - (long long)p * c);
        ret = (ret + (long long)(n - r) * gain) % MOD;

        update(cnt, total, n, p);
        last[nums[r]] = r + 1;
    }

    free(cnt);
    free(total);
    free(last);

    return (int)ret;
}
