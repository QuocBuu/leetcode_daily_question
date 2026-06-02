int reverseBits(int n) {
    uint32_t ret = 0;
    for (int i = 0; i < 31; i++) {
        uint32_t val = 0x0000000000000001;
        val &= n;
        // printf("%d", n);
        n >>= 1;
        if (val) {
            ret += 1;
        }
        ret <<= 1;
        // printf("-%d\n", ret);
    }
    return (int)ret;
}