char* smallestPalindrome(char* s) {
    int len = strlen(s);
    int freq[256] = {0};

    for (int i = 0; i < len; i++) {
        freq[(unsigned char)s[i]]++;
    }

    int left = 0;
    int right = len - 1;
    unsigned char middle = 0;

    for (int c = 0; c < 256; c++) {
        int pairs = freq[c] / 2;

        for (int i = 0; i < pairs; i++) {
            s[left++] = (char)c;
            s[right--] = (char)c;
        }

        if (freq[c] % 2 != 0) {
            middle = (unsigned char)c;
        }
    }

    if (len % 2 != 0) {
        s[len / 2] = (char)middle;
    }

    s[len] = '\0';
    return s;
}