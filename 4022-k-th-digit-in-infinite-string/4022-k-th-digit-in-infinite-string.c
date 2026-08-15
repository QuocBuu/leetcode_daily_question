int kthDigit(long long k) {
    if (k <= 9) {
        return (int)k;
    }

    k -= 9;
    long long blocks = 1;
    int digits = 2;
    while(1) {
        long long count = blocks * 9; // 10*d -> 10*d + 9
        long long len   = count * 10 * digits;

        if (len >= k) {
            break;
        }

        k -= len;
        blocks *= 10;
        digits++;
    }

    long long bBlock = (k - 1) / (10 * digits);
    long long pos = (k - 1) % (10 * digits);

    long long b = blocks + bBlock;

    long long number = 0;
    long long offset = pos / digits;
    int dOffset = pos % digits;

    if (b % 2 == 0) {
        number = 10 * b + offset;
    }
    else {
        number = 10 * b + 9 - offset;
    }

    long long div = 1;
    for (int i = 0; i < digits - dOffset - 1; i++) {
        div *= 10;
    }

    return (number / div) % 10;
}