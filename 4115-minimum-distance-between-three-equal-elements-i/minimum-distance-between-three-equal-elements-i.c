int minimumDistance(int* nums, int numsSize) {
    int array[101] = {0};
    
    for (int i = 0; i < numsSize; i++) {
        array[nums[i]]++;
    }

    int ret = INT_MAX;
    for (int i = 1; i < 101; i++) {
        if (array[i] >= 3) {
            int b0 = -1, b1 = -1, b2 = -1;
            int k = 0;
            while (array[i] != 0) {
                if (nums[k] == i) {
                    b2 = b1;
                    b1 = b0;
                    b0 = k;
                    if (b2 != -1) {
                        int vret = (b0 - b2) * 2;
                        if (vret < ret) {
                            ret = vret;
                        }
                    }
                    array[i]--;
                }
                k++;
            }
        }
    }

    return ret == INT_MAX ? -1 : ret;
}