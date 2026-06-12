bool hasAlternatingBits(int n) {
    #define MARK (1)
    int k = n & MARK;
    while (n) {
        printf("%d", k);
        n >>= MARK;
        if (!((n & MARK) - k)) {
            return false;
        }
        k = n & MARK;
    }

    return true;
}