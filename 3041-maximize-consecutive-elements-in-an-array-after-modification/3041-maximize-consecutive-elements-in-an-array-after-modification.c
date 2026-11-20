int cmp (const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int maxSelectedElements(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int arr[2] = {1, 1};
    int ret = 1;

    for (int i = 1; i < numsSize; i++) {
        int val = nums[i] - nums[i-1];
        switch(val) {
            case 0: {
                arr[1] = arr[0] + 1;
            } break;

            case 1: {
                arr[0]++;
                arr[1]++;
            } break;

            case 2: {
                arr[0] = arr[1] + 1;
                arr[1] = 1;
            } break;

            default: {
                arr[0] = arr[1] = 1;
            } break;
        }

        if (arr[0] > ret) {
            ret = arr[0];
        }

        if (arr[1] > ret) {
            ret = arr[1];
        }
    }

    return ret;
}