int check (int num) {
    if (num <= 100) {
        return 0;
    }

    int array[10];
    int k = 0;
    while (num) {
        array[k] = num % 10;
        num /= 10;
        k++;
    }

    int h = 0;
    int l = 0;

    for (int i = 1; i < (k-1); i++) {
        if (array[i] > array[i-1] && array[i] > array[i+1]) {
            h++;
        }
        else if (array[i] < array[i-1] && array[i] < array[i+1]) {
            l++;
        }
    }

    return h+l;
}
int totalWaviness(int num1, int num2) {
    int ret = 0;
    for (int i = num1; i <= num2; i++) {
        ret += check(i);
    }

    return ret;
}