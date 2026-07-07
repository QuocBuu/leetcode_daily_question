char* convert(char* s, int numRows) {
    int n = strlen(s);

    if (numRows == 1 || numRows >= n) {
        return s;
    }
    
    char* ret = malloc(n+1);
    ret[n] = '\0';
    int idx = 0;
    int cnt = 2* numRows - 2;

    for (int row = 0; row < numRows; row++) {
        for (int i = row; i < n; i += cnt) {
            // printf("%c - %d\n", s[i], i);
            ret[idx++] = s[i];
            int mid = i + cnt - 2*row;
            if (row != 0 && row != numRows - 1 && mid < n) {
                // printf("%c - %d\n", s[i], mid);
                ret[idx++] = s[mid];
            }
        }
    } 
    return ret;
}