bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    if (x < 10) {
        return true;
    }

    int array[10] = {0};
    int i = 0;
    while (x > 0) {
        int a = x % 10;
        array[i] = a;
        x /= 10;
        i++;
    }

    int q = i / 2;
    for (int k = 0; k <= q; k++) {
        if (array[k] != array[i-k-1]) {
            return false;
        }
    }
    return true;
}