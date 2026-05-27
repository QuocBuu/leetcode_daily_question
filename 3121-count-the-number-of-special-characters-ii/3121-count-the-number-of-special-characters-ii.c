int numberOfSpecialChars(char* word) {
    int lowerLast[26];
    int upperFirst[26];

    for (int i = 0; i < 26; i++) {
        lowerLast[i] = -1;
        upperFirst[i] = -1;
    }

    int len = strlen(word);

    for (int i = 0; i < len; i++) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            lowerLast[word[i] - 'a'] = i;
        } else if (word[i] >= 'A' && word[i] <= 'Z') {
            int idx = word[i] - 'A';
            if (upperFirst[idx] == -1) {
                upperFirst[idx] = i;
            }
        }
    }

    int ret = 0;

    for (int i = 0; i < 26; i++) {
        if (lowerLast[i] != -1 &&
            upperFirst[i] != -1 &&
            lowerLast[i] < upperFirst[i]) {
            ret++;
        }
    }

    return ret;
}