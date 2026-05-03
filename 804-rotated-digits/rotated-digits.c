int rotatedDigits(int n) {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        bool isChanger = false;
        bool isApprove = true;
        int value = i;
        while (value) {
            int k = value % 10;
            if (k == 3 || k == 4 || k == 7) {
                isApprove = false;
                break;
            }
            else if (k == 2 || k == 5 || k == 6 || k == 9) {
                isChanger = true;
            }

            value /= 10;
        }

        if (isApprove && isChanger) {
            ret++;
        }
    }

    return ret;
}