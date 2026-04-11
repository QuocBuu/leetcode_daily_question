bool makeEqual(char** words, int wordsSize) {
    int array[26] = {0};

    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; words[i][j]; j++) {
            array[words[i][j] - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (array[i] % wordsSize != 0) {
            return false;
        }
    }

    return true;
}