bool canReach(char* s, int minJump, int maxJump) {
    int len = strlen(s);
    if (s[len-1] != '0') {
        return false;
    }

    s[0] = 'a';
    int farthest = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'a') {
            int min = i+minJump;
            int max = i + maxJump;

            if (min < farthest) {
                min = farthest;
            }

            if (max > (len-1)) {
                max = len-1;
            }

            for (int j = min; j <= max; j++) {
                if (s[j] == '0') {
                    s[j] = 'a';
                }
            }

            if (max+1 > farthest) {
                farthest = max+1;
            }
        }
    }

    return s[len-1] == 'a' ? true : false;
}