int mirrorDistance(int n) {
    int m = 0;
    int k = n;
    while (k > 0) {
        int q = k % 10;
        m = m*10 + q;
        k /= 10;
    }

    return abs(m - n);
}