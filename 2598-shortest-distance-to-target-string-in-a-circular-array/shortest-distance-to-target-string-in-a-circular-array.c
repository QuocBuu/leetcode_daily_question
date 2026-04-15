int closestTarget(char** words, int wordsSize, char* target, int startIndex) {
    int ret = INT_MAX;
    int m = wordsSize/2;
    for (int i = 0; i < wordsSize; i++) {
        if (strcmp(words[i], target) == 0) {
            int q = abs(i - startIndex);
            int n = q > m ? (wordsSize - q) : q;
            if (ret > n) {
                ret = n;
            }
        }
    }

    return ret == INT_MAX ? -1 : ret;
}