int maxDepth(char* s) {
    int top = 0;
    int ret = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            top++;
            if (top > ret) {
                ret = top;
            }
        }
        else if (s[i] == ')') {
            top--;
        }
    }

    return ret;
}