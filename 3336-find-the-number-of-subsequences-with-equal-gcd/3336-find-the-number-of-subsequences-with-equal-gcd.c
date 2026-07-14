#define MAX_NUM  (201)
#define MOD      (1000000007)

int gcd(int a, int b) {
    while (b != 0) {
        int val = a % b;
        a = b;
        b = val;
    }
    return a;
}

int add_mod(int a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }

    return a;
}

int subsequencePairCount(int* nums, int numsSize) {
    long long sum = 0;

    int dp1[MAX_NUM][MAX_NUM] = {0};
    int dp2[MAX_NUM][MAX_NUM] = {0};

    dp1[0][0] = 1;

    for (int i = 0; i < numsSize; i++) {
        memset(dp2, 0, sizeof(dp2));
        for (int g1 = 0; g1 < MAX_NUM; g1++) {
            for (int g2 = 0; g2 < MAX_NUM; g2++) {
                int cnt = dp1[g1][g2];

                if (cnt == 0) {
                    continue;
                }

                int newG1 = gcd(g1, nums[i]);
                int newG2 = gcd(g2, nums[i]);

                dp2[newG1][g2] = add_mod(dp2[newG1][g2], cnt);
                dp2[g1][newG2] = add_mod(dp2[g1][newG2], cnt);

                dp2[g1][g2] = add_mod(dp2[g1][g2], cnt);
            }
        }

        memcpy(dp1, dp2, sizeof(dp1));
    }

    int ret = 0;
    for (int i = 1; i < MAX_NUM; i++) {
        ret = add_mod(ret, dp1[i][i]);
    }

    return ret;
}