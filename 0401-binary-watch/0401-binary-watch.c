/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int checkBit (int val) {
    int k = 0;
    while (val) {
        k += val&1;
        val >>= 1;
    }
    return k;
}

char** readBinaryWatch(int turnedOn, int* returnSize) {
    if (turnedOn >= 9) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = 0;
    char **retStr = malloc(sizeof(char*) * 60 * 12);
    for (int hh = 0; hh < 12; hh++) {
        for (int mm = 0; mm < 60; mm++) {
            if ((checkBit(hh) + checkBit(mm)) == turnedOn) {
                retStr[*returnSize] = malloc(sizeof(char) * 6);
                snprintf(retStr[*returnSize], 6, "%d:%02d", hh, mm);
                *returnSize += 1;
            }
        }
    }

    return retStr;
}