int minSumOfLengths(int* arr, int arrSize, int target) {
    int* minSize = malloc(sizeof(int) * arrSize);
    int ret = INT_MAX;
    int sum = 0;
    int minLen = INT_MAX;
    int start = 0;

    for (int end = 0; end < arrSize; end++) {
        sum += arr[end];
        while (sum > target) {
            sum -= arr[start];
            start++;
        }

        if (sum == target) {
            int len = end - start + 1;
            if (start != 0 && minSize[start - 1] != INT_MAX) {
                int total = minSize[start - 1] + len;
                if (ret > total) {
                    ret = total;
                }
            }

            if (len < minLen) {
                minLen = len;
            }
        }

        minSize[end] = minLen;
    } 

    free(minSize);

    return ret != INT_MAX ? ret : -1;
}