long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long findKthSmallest(int* coins, int coinsSize, int k) {
    int n = coinsSize;
    int num_subsets = (1 << n) - 1;
    long long lcms[32768];
    int signs[32768];
    int idx = 0;

    long long min_coin = coins[0];
    for(int i = 1; i < n; i++) {
        if(coins[i] < min_coin) min_coin = coins[i];
    }

    for (int i = 1; i < (1 << n); i++) {
        long long cur_lcm = 1;
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                count++;
                long long coin = coins[j];
                cur_lcm = (cur_lcm / gcd(cur_lcm, coin)) * coin;
            }
        }
        lcms[idx] = cur_lcm;
        signs[idx] = (count % 2 == 1) ? 1 : -1;
        idx++;
    }

    long long left = 1;
    long long right = min_coin * k;

    while (left < right) {
        long long mid = left + (right - left) / 2;
        long long cnt = 0;
        for (int i = 0; i < num_subsets; i++) {
            cnt += signs[i] * (mid / lcms[i]);
        }
        if (cnt >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}