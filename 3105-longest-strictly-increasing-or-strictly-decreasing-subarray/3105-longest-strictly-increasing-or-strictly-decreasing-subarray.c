int longestMonotonicSubarray(int* nums, int numsSize) {
    if (numsSize == 1) {
        return 1;
    }

    int ret = 1;
    int inc = 1;
    int dec = 1;
    for (int i = 0; i < numsSize-1; i++) {
        if (nums[i] == nums[i+1]) {
            inc = 1;
            dec = 1;
            continue;
        }
        else if (nums[i] < nums[i+1]) {
            inc++;
            dec = 1;
        }
        else {
            inc = 1;
            dec++;
        }

        if (inc > ret) {
            ret = inc;
        }

        if (dec > ret) {
            ret = dec;
        }
    }

    return ret;
}