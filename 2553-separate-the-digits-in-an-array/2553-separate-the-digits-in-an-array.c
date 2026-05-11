/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* separateDigits(int* nums, int numsSize, int* returnSize) {
    int* ret = malloc(sizeof(int) * 10000);

    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        int k = nums[i];
        int array[6] = {0};
        int q = 0;
        while (k > 9) {
            array[q] = k % 10;
            k /= 10;
            q++;
        }
        array[q] = k;

        for (int j = 0; j <= q; j++) {
            ret[count++] = array[q - j];
        }
    }
    *returnSize = count;
    return ret;
}