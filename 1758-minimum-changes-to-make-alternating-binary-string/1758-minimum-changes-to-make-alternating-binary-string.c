int minOperations(char* s) {
    int if0 = 0;
    int if1 = 0;
    
    for (int i = 0; i < strlen(s); i++) {
        if (i%2) {
            if (s[i] == '0') {
                if1++;
            }
            else {
                if0++;
            }
        }
        else {
            if (s[i] == '0') {
                if0++;
            }
            else {
                if1++;
            }
        }
    }

    return if0 < if1 ? if0 : if1;
}