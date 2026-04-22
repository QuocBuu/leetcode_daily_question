/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** twoEditWords(char** queries, int queriesSize, char** dictionary, int dictionarySize, int* returnSize) {
    int len = strlen(queries[0]);

    char **ret = malloc(sizeof(char*) * queriesSize);
    for (int i = 0; i < queriesSize; i++) {
        ret[i] = (char*) malloc(sizeof(char) * (len + 1));
    }

    int count = 0;
    for (int i = 0; i < queriesSize; i++) {
        for (int j = 0; j < dictionarySize; j++) {
            int diff = 0; 
            for (int k = 0; k < len; k++) {
                if (queries[i][k] != dictionary[j][k]) {
                    diff++;
                    if (diff > 2) {
                        break;
                    }
                }
            }

            if (diff <= 2) {
                strcpy(ret[count], queries[i]);
                count++;
                break;
            }
        }
    }
    *returnSize = count;
    return ret;
}