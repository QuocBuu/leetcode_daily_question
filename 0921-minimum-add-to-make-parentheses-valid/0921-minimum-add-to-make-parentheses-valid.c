int minAddToMakeValid(char* s) {
    int addClose = 0;
    int addOpen  = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            addClose++;
        }
        else {
            if (addClose > 0) {
                addClose--;
            }
            else {
                addOpen++;
            }
        }
    }

    return addOpen + addClose;
}