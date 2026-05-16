int cmp (const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int size = nums1Size+nums2Size;
    int array[size];

    memcpy(array, nums1, nums1Size * sizeof(int));
    memcpy(array+nums1Size, nums2, nums2Size * sizeof(int));

    qsort(array, nums1Size + nums2Size, sizeof(int), cmp);

    // for (int i = 0; i < size; i++) {
    //     printf("%d - %d\n", array[i], size);
    // }

    int halfSize = size/2; 
    if (size % 2 == 0) {
        return ((double)(array[halfSize] + array[halfSize-1])) / 2;
    }

    return (double)array[halfSize];
}