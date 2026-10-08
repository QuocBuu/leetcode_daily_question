char* removeOuterParentheses(char* s) {
    int len = strlen(s);
    char* ret = malloc(sizeof(char) * len);
    int cnt = 0;
    int val = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            val++;
            if (val != 1) {
                ret[cnt++] = s[i];
            }
        }
        else {
            val--;
            if (val != 0) {
                ret[cnt++] = s[i];
            }
        }
    }

    ret[cnt] = '\0';
    return ret;
}