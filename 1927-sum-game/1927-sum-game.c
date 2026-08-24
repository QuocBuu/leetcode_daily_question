bool sumGame(char* num) {
    int sumRight = 0;
    int sumLeft  = 0;
    int qRight   = 0;
    int qLeft    = 0;
    int len = strlen(num);
    for (int i = 0; i < len; i++) {
        if (i < ((len + 1) / 2)) {
            if (num[i] == '?') {
                qRight++;
            }
            else {
                sumRight += num[i] - '0';
            }
        }
        else {
            if (num[i] == '?') {
                qLeft++;
            }
            else {
                sumLeft += num[i] - '0';
            }
        }
    }

    if (qLeft == qRight) {
        return sumLeft != sumRight;
    }

    if ((qLeft + qRight) % 2) {
        return true;
    }

    return 2 * (sumLeft - sumRight) != 9 * (qRight - qLeft);
}