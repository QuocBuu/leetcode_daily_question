int reverseDegree(char* s) {
    int len = strlen(s);
    int ret = 0;
    for (int i = 0; i < len; i++) {
        // printf("[%c] %d -> %d\n", s[i], s[i], (26 - s[i] + 'a'));
        ret += (i + 1) * (26 - s[i] + 'a');
    }

    return ret;
}