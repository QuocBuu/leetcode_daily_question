#define MOD 1000000007LL

long long modPow(long long base, long long exp) {
    long long ret = 1;

    while (exp > 0) {
        if (exp & 1) {
            ret = ret * base % MOD;
        }

        base = base * base % MOD;
        exp >>= 1;
    }

    return ret;
}

int numberOfSets(int n, int k) {
    long long len = n + k - 1;
    long long cnt = 2LL * k;

    if (cnt > len - cnt) {
        cnt = len - cnt;
    }

    long long top = 1;
    long long bot = 1;

    for (long long i = 1; i <= cnt; i++) {
        top = top * (len - cnt + i) % MOD;
        bot = bot * i % MOD;
    }

    long long inv = modPow(bot, MOD - 2);

    return (int)(top * inv % MOD);
}