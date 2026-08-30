int countSpecialIntegers(int* nums, int numsSize) {
    int cnt = 1;
    int val = nums[0];
    int arr[101] = {0};
    arr[val] = 1;
    for (int i = 1; i < numsSize; i++) {
        if (val != nums[i]) {
            nums[cnt++] = nums[i];
            val = nums[i];
            arr[val]++;
        }
    }

    int ret = 0;
    for (int i = 1; i < 101; i++) {
        if (arr[i] == 1) {
            ret++;
        }
    }
    
    return ret;
}