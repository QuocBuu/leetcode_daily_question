int mirrorDistance(int n) {
    int m = 0;
    int k = n;
    while (k > 0) {
        m = m*10 + k % 10;
        k /= 10;
    }

    return abs(m - n);
}