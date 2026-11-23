bool checkString(char* s) {
    if (s[1] == '\0') {
        return true;
    }

    int cnt = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'b') {
            cnt++;
            // printf("%d\n", cnt);
        }
        else {
            if (cnt != 0) {
                return false;
            }
        }
    }

    return true;
}