int maxPalindromes(char* s, int k) {
    int len = strlen(s);
    if (k == 1) {
        return len;
    }

    int ret = 0;
    for (int i = 0; i <= len - k;) {
        int step = 1;

        int d = k;
        while(d <= k+1) {
            if (i + d > len) {
                break;
            }

            bool isTrue = true;
            for (int j = 0; j < d/2; j++) {
                if (s[i+j] != s[i + d - j - 1]) {
                    isTrue = false;
                    break;
                }
            }

            if (isTrue) {
                step = d;
                ret++;
                break;
            }

            d++;
        }

        i += step;
    }

    return ret;
}