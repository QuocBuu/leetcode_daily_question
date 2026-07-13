/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void digVal (int val, int *size) {
    while (val) {
        val /= 10;
        (*size)++; 
    }
}

int* sequentialDigits(int low, int high, int* returnSize) {
    int digLow = 0;
    int digHig = 0;

    digVal(low, &digLow);
    digVal(high, &digHig);
    // printf("%d - %d\n", digLow, digHig);

    if (high < low) {
        *returnSize = 0;
        return NULL;
    }

    int* ret = malloc(sizeof(int) * 36);
    *returnSize = 0;
    for (int dig = digLow; dig <= digHig; dig++) {
        for (int k = dig; k <= 9; k++) {
            int val = 0;
            for (int i = dig-1; i >= 0; i--) {
                val = (k - i + val) * 10;
            }
            val /= 10;

            if (val >= low) {
                if (val > high) {
                    goto end;
                }

                ret[*returnSize] = val;
                (*returnSize)++; 
            }
            // printf("%d\n", val);
        }
    }

end:
    return ret;
}