int cmpDesc(const void* a, const void* b) {
    return *(const int*)b - *(const int*)a;
}

long long minSumSquareDiff(int* nums1, int nums1Size, int* nums2, int nums2Size,
                           int k1, int k2) {
    long long k = (long long)k1 + k2;
    int n = nums1Size;

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        nums1[i] = abs(nums1[i] - nums2[i]);
        sum += nums1[i];
    }
    if (sum <= k) {
        return 0;
    }

    qsort(nums1, n, sizeof(int), cmpDesc);
    for (int i = 1; i <= n; i++) {
        int next = i < n ? nums1[i] : 0;
        long long cost = (long long)(nums1[i - 1] - next) * i;
        if (cost > k) {
            long long q = k / i, r = k % i, hi = nums1[i - 1] - q;
            long long ans = hi * hi * (i - r) + (hi - 1) * (hi - 1) * r;
            for (int j = i; j < n; j++) {
                ans += (long long)nums1[j] * nums1[j];
            }
            return ans;
        }
        k -= cost;
    }
    return 0;
}