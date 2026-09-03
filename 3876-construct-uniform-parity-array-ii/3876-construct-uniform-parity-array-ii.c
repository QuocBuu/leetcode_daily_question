bool uniformArray(int* nums1, int nums1Size) {
    bool even = false;
    bool odd = false;
    int min = nums1[0];
    for (int i = 0; i < nums1Size; i++) {
        if (!even && nums1[i] % 2 == 0) {
            even = true;
        }

        if (!odd && nums1[i] % 2 == 1) {
            odd = true;
        }

        if (min > nums1[i]) {
            min = nums1[i];
        }
    }

    if (min % 2 == 0 && (even && odd)) {
        return false;
    }
    
    return true;
}