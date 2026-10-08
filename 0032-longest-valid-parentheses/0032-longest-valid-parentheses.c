int longestValidParentheses(char* s) {
    int len = strlen(s);
    int* stack = malloc(sizeof(int) * (len + 2));
    stack[0] = -1;
    int cnt = 1;
    int ret = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            stack[cnt++] = i;
        }
        else {
            stack[cnt--] = 0;
            if (cnt == 0) {
                stack[cnt++] = i;
            }
            else {
                int val = i - stack[cnt-1];
                if (val > ret) {
                    ret = val;
                }
            }
        }
    }

    free(stack);
    return ret;
}