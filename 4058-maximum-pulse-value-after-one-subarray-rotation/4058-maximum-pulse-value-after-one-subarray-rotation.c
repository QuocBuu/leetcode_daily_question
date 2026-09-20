long long maxValue(int* nums, int numsSize) {
    long long val = 0;
    long long prefix = 0;
    long long maxPre[2] = {0, LLONG_MIN};
    long long maxGain = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i % 2 == 0) {
            prefix += nums[i];
        }
        else {
            prefix -= nums[i];
        }

        val = prefix;

        int index = i + 1;
        int parity = index % 2;
        if (maxPre[parity] != LLONG_MIN) {
            long long gain = 2 * (maxPre[parity] - prefix);
            if (gain > maxGain) {
                maxGain = gain;
            }
        }

        if (prefix > maxPre[parity]) {
            maxPre[parity] = prefix;
        }
    }

    return val + maxGain;
}