#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long power(long long base, long long exp) {
    long long res = 1;
    long long mod = 1000000007;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, 1000000007 - 2);
}

int xorAfterQueries(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    long long MOD = 1000000007;
    int limit = (int)sqrt(numsSize);
    
    // 1. Process Large K (Brute Force)
    for (int i = 0; i < queriesSize; i++) {
        int l = queries[i][0], r = queries[i][1], k = queries[i][2], v = queries[i][3];
        if (k >= limit) {
            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = (int)((1LL * nums[idx] * v) % MOD);
            }
        }
    }

    // 2. Process Small K (Difference Array / Prefix Product)
    long long* diff = (long long*)malloc(numsSize * sizeof(long long));
    for (int k = 1; k < limit; k++) {
        int found = 0;
        for (int j = 0; j < numsSize; j++) diff[j] = 1;

        for (int i = 0; i < queriesSize; i++) {
            if (queries[i][2] == k) {
                int l = queries[i][0], r = queries[i][1], v = queries[i][3];
                found = 1;
                diff[l] = (diff[l] * v) % MOD;
                int steps = (r - l) / k;
                int nxt = l + (steps + 1) * k;
                if (nxt < numsSize) {
                    diff[nxt] = (diff[nxt] * modInverse(v)) % MOD;
                }
            }
        }

        if (found) {
            for (int i = 0; i < numsSize; i++) {
                if (i >= k) diff[i] = (diff[i] * diff[i - k]) % MOD;
                nums[i] = (int)((1LL * nums[i] * diff[i]) % MOD);
            }
        }
    }

    // 3. Final XOR
    int ans = 0;
    for (int i = 0; i < numsSize; i++) ans ^= nums[i];
    
    free(diff);
    return ans;
}