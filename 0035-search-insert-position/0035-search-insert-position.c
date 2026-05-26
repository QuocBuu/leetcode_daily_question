int searchInsert(int* nums, int numsSize, int target) {
    if (target < nums[0]) {
        return 0;
    }

    if (target > nums[numsSize-1]) {
        return numsSize;
    }

    int k = target - nums[0];
    if (k >= numsSize) {
        k = numsSize-1;
    }

    if (nums[k] > target) {
        while (nums[k] >= target) {
            k--;
            printf("-- %d\n", k);
        }
        return k+1;
    }
    else if (nums[k] == target) {
        return k;
    }
    else {
        while (nums[k] < target) {
            printf("++ %d\n", k);
            k++;
        }
        return k;
    }
}