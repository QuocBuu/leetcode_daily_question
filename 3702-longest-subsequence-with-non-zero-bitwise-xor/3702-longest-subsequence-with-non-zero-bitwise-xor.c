int allXOR (int* nums, int numsSize) {
    int ret = 0;
    for (int i = 0; i < numsSize; i++) {
        ret ^= nums[i];
    }
    return ret;
}

int longestSubsequence(int* nums, int numsSize) {
    int ret = 0;
    int totalXOR = allXOR(nums, numsSize);

    if (totalXOR) {
        return numsSize;
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            continue;
        }
        else {
            ret = numsSize - 1;
            break;
        }
    }

    return ret;
}