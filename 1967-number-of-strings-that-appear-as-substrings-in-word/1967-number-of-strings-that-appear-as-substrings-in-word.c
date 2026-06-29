int check(char *pattern, int n, char* word, int size) {
    int ret = 0;

    if (n > size) {
        return ret;
    }

    char *pos = strstr(word, pattern);
    if (pos != NULL) {
        ret = 1;
    }

    return ret;
}

int numOfStrings(char** patterns, int patternsSize, char* word) {
    int ret = 0;

    int size = strlen(word);

    for (int i = 0; i < patternsSize; i++) {
        int n = strlen(patterns[i]);
        ret += check(patterns[i], n, word, size);
    }

    return ret;
}