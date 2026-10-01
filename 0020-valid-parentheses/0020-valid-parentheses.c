bool isValid(char* s) {
    int len = strlen(s);
    int val = 0;
    if (len % 2 == 1) {
        return false;
    }

    // printf("%d - %d\n", '(',')');
    // printf("%d - %d\n", '{','}');
    // printf("%d - %d\n", '[',']');

    for (int i = 0; i < len; i++) {
        if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            val = i - 1;
            while (val >= 0 && s[val] == 'a') {
                val--;
            }
            if (val < 0) {
                return false;
            }

            int q = abs(s[i] - s[val]);
            if (q != 1 && q != 2) {
                return false;
            }
            else {
                s[i] = 'a';
                s[val] = 'a';
            }
            continue;
        }
    }

    for (int i = 0; i < len; i++) {
        if (s[i] != 'a') {
            return false;
        }
    }
    return true;
}