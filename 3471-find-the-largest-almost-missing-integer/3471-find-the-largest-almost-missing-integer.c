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