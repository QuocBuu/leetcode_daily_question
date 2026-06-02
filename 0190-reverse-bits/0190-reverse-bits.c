#define BIT (1)
int reverseBits(int n) {
    int ret = 0;
    for (int i = 0; i < 31; i++) {
        if (n & BIT) {
            ret += BIT;
        }
        n >>= BIT;
        ret <<= BIT;
    }
    return ret;
}