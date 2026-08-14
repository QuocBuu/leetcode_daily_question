int maximumLengthSubstring(char* s) {
    int len = strlen(s);
    int ret = 0;
    int arr[26] = {0};

    for (int left = 0, right = 0; right < len; right++) {
        arr[(s[right] & 31) - 1]++;

        while (arr[(s[right] & 31) - 1] > 2) {
            arr[(s[left] & 31) - 1]--;
            left++;
        }

        int max = right - left + 1;
        if (max > ret) {
            ret = max;
        }
    }

    return ret;
}