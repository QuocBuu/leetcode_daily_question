bool canAliceWin(int n) {
    if (n < 10) {
        return false;
    }

    for (int i = 10; i >= 1; i--) {
        if (i <= n) {
            n -= i;
        }
        else {
            return i % 2;
        }
    }

    return true;
}