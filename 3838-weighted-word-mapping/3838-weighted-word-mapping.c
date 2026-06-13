char* mapWordWeights(char** words, int wordsSize, int* weights, int weightsSize) {
    char *ret = malloc(sizeof(char)*(wordsSize + 1));
    ret[wordsSize] = '\0';
    for (int i = 0; i < wordsSize; i++) {
        int len = strlen(words[i]);
        int max = 0;
        for (int j = 0; j < len; j++) {
            // printf("%c", words[i][j]);
            max += weights[words[i][j] - 'a'];
        }
        max %= 26;
        // printf("\n max = %d\n", max);
        ret[i] = 'a' + 25 - max;
    }

    return ret;
}