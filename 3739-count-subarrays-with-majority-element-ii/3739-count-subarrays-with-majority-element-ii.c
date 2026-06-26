long long countMajoritySubarrays(int* nums, int numsSize, int target) {
    long long ret = 0;
    int* pref = calloc(numsSize*2 + 1, sizeof(int));
    int cnt = numsSize;
    int prefSum = 0;
    pref[numsSize] = 1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            prefSum += pref[cnt];
            cnt++;
            pref[cnt]++;
        }
        else {
            cnt--;
            prefSum -= pref[cnt];
            pref[cnt]++;
        }
        ret += prefSum;
    }

    free(pref);
    return ret;
}