int maxDistance(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0, j = 0;
    int ret = 0;

    while (i < nums1Size && j < nums2Size) {
        if (i > j) {
            j = i;
        }

        if (j >= nums2Size) {
            break;
        }

        if (nums1[i] <= nums2[j]) {
            if ((j - i) > ret) {
                ret = j - i;
            } 
            j++;
        }
        else {
            i++;
        }
    }

    return ret;
}