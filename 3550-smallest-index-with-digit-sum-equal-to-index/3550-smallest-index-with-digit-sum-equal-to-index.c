int totalNums(int a) {
    int ret = 0;
    while (a) {
        ret += a % 10;
        a /= 10;
    }
    return ret;
}

int smallestIndex(int* nums, int numsSize) {
    int ret = INT_MAX;
    for (int i = 0; i < numsSize; i++) {
        if (i == totalNums(nums[i])) {
            if (ret > i) {
                ret = i;
            }
        } 
    }

    return ret == INT_MAX ? -1 : ret;
}