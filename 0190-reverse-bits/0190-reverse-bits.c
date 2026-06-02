int reverseBits(int n) {
    int ret = 0;
    for (int i = 0; i < 31; i++) {
        if (n & 1) {
            ret += 1;
        }
        n >>= 1;
        ret <<= 1;
    }
    return ret;
}