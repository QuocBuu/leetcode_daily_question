int minOperations(int* nums, int numsSize, int x) {
    int total = 0;
    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
    }

    if (total < x) {
        return -1;
    }

    if (total == x) {
        return numsSize;
    }

    int target = total - x;
    int sum = 0;
    int left = 0;
    int minLen = INT_MAX;

    for (int right = 0; right < numsSize; right++) {
        sum += nums[right];

        while (sum > target && left < right) {
            sum -= nums[left++];
        }

        if (sum == target) {
            int len = numsSize - right + left - 1;
            minLen = minLen > len ? len : minLen;
        }
    }

    return minLen != INT_MAX ? minLen : -1;
}