int bitwiseComplement(int n) {
    if (n == 0) {
        return 1;
    }
    int k = ~n;
    int cbit = 0;
    while (n > 0) {
        n >>= 1;
        cbit <<= 1;
        cbit++;
    }
    return cbit & k;
}