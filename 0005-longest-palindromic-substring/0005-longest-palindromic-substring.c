char* longestPalindrome(char* s) {
    int len = strlen(s);
    char* ret = malloc(sizeof(char) * len + 1);
    ret[0] = s[0];
    int max = 1;

    if (len == 1) {
        ret[max] = '\0';
        return ret; 
    }

    for (int i = 0; i < len - 1; i++) {
        int right = i;
        int left  = i+1;
        int isTrue = false;
        if (s[left] == s[right]) {
            while (right >= 0 && left < len) {
                if (s[left] != s[right]) {
                    break;
                }
                right--;
                left++;
            }
            int val = left - right - 1;
            if (val > max) {
                max = val;
                memcpy(ret, s + right + 1, sizeof(char) * max);
            }
        }

        right = i;
        left  = i + 2 >= len ? len - 1 : i + 2;        
        if (s[left] == s[right]) {
            while (right >= 0 && left < len) {
                if (s[left] != s[right]) {
                    break;
                }
                right--;
                left++;
            }
            int val = left - right - 1;
            if (val > max) {
                max = val;
                memcpy(ret, s + right + 1, sizeof(char) * max);
            }
        }
    }

    ret[max] = '\0';
    return ret;
}