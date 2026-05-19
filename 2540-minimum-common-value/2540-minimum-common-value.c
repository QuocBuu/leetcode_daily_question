int cmp (const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int arr[nums1Size+nums2Size];

    arr[0] = nums1[0];
    int count = 0;
    for (int i = 1; i < nums1Size; i++) {
        if (arr[count] != nums1[i]) {
            arr[++count] = nums1[i];
            // printf("%d - %d\n", count, arr[count]);
        }
    }

    arr[++count] = nums2[0];
    for (int i = 1; i < nums2Size; i++) {
        if (arr[count] != nums2[i]) {
            arr[++count] = nums2[i];
            // printf("%d - %d\n", count, arr[count]);
        }
    }

    qsort(arr, count+1, sizeof(int), cmp);

    for (int i = 1; i <= count; i++) {
        // printf("%d - %d\n", i, arr[i]);
        if (arr[i] == arr[i-1]) {
            return arr[i];
        }
    }

    return -1;
}