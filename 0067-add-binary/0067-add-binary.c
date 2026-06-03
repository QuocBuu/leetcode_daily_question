char* addBinary(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = (lenA > lenB ? lenA : lenB) + 2;
    char *ret = malloc(sizeof(char) * (maxLen));
    memset(ret, '0', sizeof(char)*maxLen);
    int rem = 0;
    ret[--maxLen] = '\0';
    while (lenA || lenB) {
        int valA = 0;
        int valB = 0;
        if (lenA && a[lenA-1] == '1') {
            valA = 1;
        }
        if (lenB && b[lenB-1] == '1') {
            valB = 1;
        }
        
        int val = valA + valB + rem;
        lenA ? lenA-- : lenA;
        lenB ? lenB-- : lenB;
        rem = 0;
        if (val == 0) {
            ret[--maxLen] = '0';
        }
        else if (val == 1) {
            ret[--maxLen] = '1';
        }
        else if (val == 2) {
            ret[--maxLen] = '0';
            rem = 1;
        }
        else if (val == 3) {
            ret[--maxLen] = '1';
            rem = 1;
        }
        
    }

    if (rem && maxLen) {
        ret[--maxLen] = '1';
    }
    else {
        size_t size = strlen(ret);
        for (int i = 0; i < size; i++) {
            ret[i] = ret[i+1];
        }
    }
    return ret;
}