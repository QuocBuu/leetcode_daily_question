bool checkOnesSegment(char* s) {
    int len  = strlen(s);
    if (len == 1) {
        return s[0] == '1';
    }

    int k = 0;
    for (int i = 1; i < len; i++) {
        if (s[i] != s[i-1]) {
            k++;
        }
        if (k > 2) {
            return false;
        }
    }

    if ((k == 0 && s[0] == '1') || k == 1 || (k == 2 && s[0] == '0')) {
        return true;
    } 
    
    return false;
}