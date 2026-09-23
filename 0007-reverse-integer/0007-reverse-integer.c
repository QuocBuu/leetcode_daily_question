int reverse(int x){
    bool isNegative = x < 0 ? true : false;
    long long val = (long long)x * (isNegative == true ? -1 : 1);
    int arr[12] = {0};
    int cnt = 0;
    while (val) {
        arr[cnt++] = val % 10;
        val /= 10;
    }

    val = 0;
    for (int i = 0; i < cnt; i++) {
        val = val*10 + arr[i];
    }

    if (val > 2147483648) {
        return 0;
    }

    return val * (isNegative == true ? -1 : 1);
}