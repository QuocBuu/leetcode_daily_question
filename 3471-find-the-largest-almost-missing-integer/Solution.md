# Simple Code C - Use case analysis and qsort() - 0ms

# Intuition

The answer depends on the value of `k`. Handle the special cases `k = 1`, `k = n`, and the middle range separately.

# Approach

1. If `k == 1`, sort the array and find the largest value that appears exactly once.
2. If `k == numsSize`, return the maximum element.
3. Otherwise, only the first and last elements can be valid candidates.
4. Check whether these candidates also appear in the middle of the array.
5. Return the larger valid candidate, or `-1`.

# Complexity

* Time complexity: $$O(n \log n)$$

* Space complexity: $$O(\log n)$$

# Code

```c
int cmp (const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int largestInteger(int* nums, int numsSize, int k) {
    if (k == 1) {
        // MAX NUM
        qsort(nums, numsSize, sizeof(int), cmp);

        for (int i = numsSize - 1; i >= 0; ) {
            int val = nums[i];
            int count = 0;

            while (i >= 0 && nums[i] == val) {
                count++;
                i--;
            }

            if (count == 1) {
                return val;
            }
        }

        return -1;
    }
    else if (k == numsSize) {
        int max = INT_MIN;
        for (int i = 0; i < numsSize; i++) {
            if (max < nums[i]) {
                max = nums[i];
            }
        }
        return max;
    }
    else if (nums[0] != nums[numsSize-1]){
        // nums[0] or nums[n-1] or -1
        int arr[2] = {nums[0], nums[numsSize-1]};
        // printf("%d - %d\n", arr[0], arr[1]);
        for (int i = 1; i < (numsSize - 1); i++) {
            if (nums[i] == arr[0]) {
                arr[0] = -1;
            }
            if (nums[i] == arr[1]) {
                arr[1] = -1;
            }
            // printf("%d : %d - %d\n", i, arr[0], arr[1]);
        }

        return arr[0] > arr[1] ? arr[0] : arr[1];
    }

    return -1;
}
```
