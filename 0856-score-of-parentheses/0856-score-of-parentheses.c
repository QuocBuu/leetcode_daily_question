int scoreOfParentheses(char* s) {
    int deep = 0;
    int ret = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            deep++;
            // printf("%d\n", '(');
        }
        else {
            deep--;
            // printf("%d\n", deep);
            if (s[i-1] == '(') {
                ret += 1 << deep;
                // printf("%d\n", 1<<deep);
            }
        }
    }
    return ret;
}