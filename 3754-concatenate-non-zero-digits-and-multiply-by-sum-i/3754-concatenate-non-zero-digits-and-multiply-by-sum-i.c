long long sumAndMultiply(int n) {
    int arr[11];
    memset(arr, 0, sizeof(int) * 11);

    int cnt = 0;
    while (n) {
        arr[cnt] = n % 10;
        // printf("N - %d\n", arr[cnt]);
        n /= 10;
        cnt++;
    }

    int sum = 0;
    long long ret = 0;
    for (int i = cnt - 1; i >= 0; i--) {
        if (arr[i] != 0) {
            sum += arr[i];
            ret += arr[i];
            ret *= 10;
            // printf("R - %d\n", arr[i]);
        }
    }

    ret /= 10;

    return ret * sum;
}