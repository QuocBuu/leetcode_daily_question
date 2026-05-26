int numberOfSpecialChars(char* word) {
    int ret = 0;
    // printf("a[%d] -> z[%d], A[%d] -> Z[%d]", 'a', 'z', 'A', 'Z');
    char array[58] = {0};
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        array[word[i]-65]++;
    }

    for (int i = 0; i <= ('z' - 'a'); i++) {
        // printf("%c", i + 'a');
        if (array[i+'a'-65] > 0) {
            if (array[i+'A'-65] > 0) {
                ret++;
            }
        }
    }
    return ret;
}