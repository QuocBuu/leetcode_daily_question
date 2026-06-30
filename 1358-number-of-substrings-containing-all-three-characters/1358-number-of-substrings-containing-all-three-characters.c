int numberOfSubstrings(char* s) {
    int size = strlen(s);
    int ret = 0;

    int check[3] = {-1, -1, -1};

    for (int i = 0; i < size; i++) {
        check[s[i] - 'a'] = i;

        int min = check[0];
        min = check[1] < min ? check[1] : min;
        min = check[2] < min ? check[2] : min;

        if (min != -1) {
            ret += min + 1;
        }
    }

    return ret;
}