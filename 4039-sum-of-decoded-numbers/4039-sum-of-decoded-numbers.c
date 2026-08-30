#define MOD 1000000007
long long cal (long long x, long long y) {
    long long ret = 1;

    x %= MOD;
    
    while(y) {
        if (y % 2 == 1) {
            ret = (ret * x) % MOD;
        }

        x = (x * x) % MOD;
        y /= 2;
    }

    return ret;
}

int sumDecoded(long long* nums, int numsSize) {
    long long ret = 0;
    for (int i = 0; i < numsSize; i++) {
        long long val = nums[i];
        int width = val % 10;
        long long d = floor(val / 10);
        // printf("%d - %d - %d\n", val, width, d);

        long long code = d;
        int digit = 0;
        while (code) {
            digit++;
            code /= 10;
        }

        int k = digit - width;
        long long p = 1;
        for (int i = 0; i < k; i++) {
            p *= 10;
        }

        long long x = d / p;
        long long y = d % p;

        long long decode = cal(x, y);
        ret = (ret + decode) % MOD;
    }

    return ret;
}