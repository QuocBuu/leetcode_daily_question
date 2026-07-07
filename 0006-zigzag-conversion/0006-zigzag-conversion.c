char* convert(char* s, int numRows) {
    int n = strlen(s);

    if (numRows == 1 || numRows >= n) {
        return s;
    }
    int *cnt = calloc(numRows, sizeof(int));
    char **arr = malloc(sizeof(char*) * numRows);
    for (int i = 0; i < numRows; i++) {
        arr[i] = malloc(sizeof(char) * n);
    }

    bool check = false;
    int k = 0;
    for (int i = 0; i < n; i++) {            
        arr[k][cnt[k]] = s[i];
        cnt[k]++;
        
        if (k == 0) {
            check = true;
        }
        if (k == (numRows - 1)) {
            check = false;
        }

        k += check ? 1 : -1;
    }

    int sum = 0;
    for (int i = 0; i < numRows; i++) {
        memcpy(s+sum, arr[i], cnt[i]);
        sum += cnt[i];
        free(arr[i]);
    }
    free(arr);
    free(cnt);

    return s;
}