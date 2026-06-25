int countMajoritySubarrays(int* nums, int numsSize, int target) {
    int max = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != target) {
            nums[i] = 0;
        }
        else {
            nums[i] = 1;
            max++;
        }
    }

    if (max <= 1) {
        return max;
    }

    int ret = max;
    // printf("Max[%d]\n", max);
    max = (max << 1) - 1;

    int *pref = malloc((numsSize + 1) * sizeof(int));
    pref[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        pref[i+1] = pref[i] + nums[i];
    }

    for (int len = 2; len <= max; len++) {
        int val = (len >> 1) + 1;
        // printf("Val[%d] - len[%d]\n", val, len);
        for (int start = 0; (start + len) <= numsSize; start++) {
            int end = start + len;
            int sum = pref[end] - pref[start];
            if (sum >= val) {
                // printf("m[%d] - n[%d]\n", start, end);
                ret++;
            }
        }
    }

    free(pref);
    return ret;
}