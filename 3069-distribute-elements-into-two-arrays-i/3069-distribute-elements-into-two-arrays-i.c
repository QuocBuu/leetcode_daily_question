/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* resultArray(int* nums, int numsSize, int* returnSize) {
    int* arr1 = malloc(sizeof(int) * numsSize);
    int* arr2 = malloc(sizeof(int) * numsSize);
    int cnt1 = 1;
    int cnt2 = 1;

    arr1[0] = nums[0];
    arr2[0] = nums[1];

    for (int i = 2; i < numsSize; i++) {
        // printf("%d - %d - %d\n", i, arr1[cnt1], arr2[cnt2]);
        if (arr1[cnt1-1] > arr2[cnt2-1]) {
            arr1[cnt1] = nums[i];
            cnt1++;
        }
        else {
            arr2[cnt2] = nums[i];
            cnt2++;
        }
    }

    *returnSize = cnt1 + cnt2;
    int* ret = malloc(sizeof(int) * (cnt1 + cnt2));

    // printf("D: %d - %d - %d\n", *returnSize, cnt1, cnt2);

    memcpy(ret, arr1, sizeof(int) * cnt1);
    memcpy(ret + cnt1, arr2, sizeof(int) * cnt2);
    free(arr1);
    free(arr2);

    return ret;
}