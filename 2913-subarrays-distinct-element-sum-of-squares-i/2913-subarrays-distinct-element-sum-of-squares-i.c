int sumCounts(int* nums, int numsSize) {
    bool arr[101] = {0};
    int ret = 0;
    for (int i = 0; i < numsSize; i++) {
        int cnt = 0;
        memset(arr, 0, sizeof(bool) * 101);
        for (int j = i; j < numsSize; j++) {
            int val = nums[j];
            if (!arr[val]) {
                arr[val] = true;
                cnt++;
            }
            ret += cnt * cnt;
        }
    }

    return ret;
}