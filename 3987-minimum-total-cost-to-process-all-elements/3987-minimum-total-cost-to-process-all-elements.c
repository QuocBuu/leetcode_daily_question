int minimumCost(int* nums, int numsSize, int k) {
    #define MOD (1000000007)
    long long sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    if (sum == 0) {
        return 0;
    }

    long long op1 = (sum - 1) / k;
    long long op2 = op1 + 1;

    if (op1 % 2 == 0) {
        op1 /= 2;
    }
    else {
        op2 /= 2;
    }
    return (int) ((op1 % MOD) * (op2 % MOD) % MOD);
}