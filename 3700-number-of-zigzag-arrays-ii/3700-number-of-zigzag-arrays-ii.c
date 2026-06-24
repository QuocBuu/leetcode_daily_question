#define MOD 1000000007
static void mult(int *A, int *B, int *C, int size) {
    int sizeM = size * size;
    int *tmp = (int *)malloc(sizeof(int) * sizeM);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            long long sum = 0;

            for (int k = 0; k < size; k++) {
                sum = (sum + (long long)A[i * size + k] * B[k * size + j]) % MOD;
            }

            tmp[i * size + j] = (int)sum;
        }
    }

    memcpy(C, tmp, sizeof(int) * sizeM);
    free(tmp);
}

static void mat_pow(int *M, int power, int *ret, int size) {
    int sizeM = size * size;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            ret[i * size + j] = (i == j);
        }
    }

    int *base = (int *)malloc(sizeof(int) * sizeM);
    memcpy(base, M, sizeof(int) * sizeM);

    while (power > 0) {
        if (power & 1) {
            mult(ret, base, ret, size);
        }

        mult(base, base, base, size);
        power >>= 1;
    }

    free(base);
}

int zigZagArrays(int n, int l, int r) {
    // r <-> l => 0 <-> m-1 
    int m = r - l + 1;

    // Make matric m*m 
    int sizeM = m*m;
    int *matricUp = malloc(sizeof(int) * sizeM);
    int *matricDown = malloc(sizeof(int) * sizeM);

    // Init data in Matric
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            matricUp[i*m + j] = (i < j);
            matricDown[i*m + j] = (i > j);
        }
    }

    n -= 1;
    int k = n>>1;
    int *matricMix = malloc(sizeof(int) * sizeM);
    int *matricSin = malloc(sizeof(int) * sizeM);

    long long ret = 0;

    mult(matricUp, matricDown, matricSin, m);
    mat_pow(matricSin, k, matricMix, m);

    if (n & 1) {
        mult(matricDown, matricMix, matricMix, m);
    }


    for (int i = 0; i < sizeM; i++) {
        ret = (ret + matricMix[i]) % MOD;
    }

    ret = ret * 2 % MOD;

    free(matricUp);
    free(matricDown);
    free(matricMix);
    free(matricSin);

    return ret;
}