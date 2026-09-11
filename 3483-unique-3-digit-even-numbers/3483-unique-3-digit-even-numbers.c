int totalNumbers(int* digits, int digitsSize) {
    int f[10] = {0};
    int ret = 0;

    for (int i = 0; i < digitsSize; i++) {
        f[digits[i]]++;
    }

    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 9; k += 2) {
                ret += f[i] > 0 &&
                       f[j] > (i == j) &&
                       f[k] > (i == k) + (j == k);
            }
        }
    }

    return ret;
}