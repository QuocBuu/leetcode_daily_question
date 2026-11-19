int minChanges(char* s) {
    int ret = 0;
    for (int i = 0; i < strlen(s); i += 2) {
        if (s[i] != s[i+1]) {
            ret++;
        }
    }

    return ret;
}