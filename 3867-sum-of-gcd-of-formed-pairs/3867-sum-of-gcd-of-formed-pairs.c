#define MAX_VAL(a, b) (((a) > (b)) ? (a) : (b))

int gcd (int a, int b) {
    while (b != 0) {
        int val = a % b;
        a = b;
        b = val;
    }
    return a;
}

int cmp (const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

long long gcdSum(int* nums, int numsSize) {
    int max = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        max = MAX_VAL(max, nums[i]);
        nums[i] = gcd(max, nums[i]);
        // printf("%d - %d - %d\n", i, max, nums[i]);
    }

    qsort(nums, numsSize, sizeof(int), cmp);
    int cnt = numsSize >> 1;
    long long ret = 0;
    for (int i = (cnt - 1); i >= 0; i--) {
        ret += gcd(nums[i], nums[(numsSize - 1) - i]);
        // printf("ret >> %lld - %d - %d - %d\n", ret, i, nums[i], nums[(numsSize - 1) - i]);
    }

    return ret;
}