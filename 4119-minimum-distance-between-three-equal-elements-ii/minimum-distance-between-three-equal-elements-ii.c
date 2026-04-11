#define MAX (100001)

int minimumDistance(int* nums, int numsSize) {
    int b1Array[MAX];
    int b2Array[MAX];

    memset(b1Array, -1, sizeof(int) * MAX);
    memset(b2Array, -1, sizeof(int) * MAX);

    int ret = INT_MAX;
    for (int i = 0; i < numsSize; i++) {
        int value = nums[i];
        if (b2Array[value] != -1) {
            int vret = (i - b2Array[value]) * 2;
            if (vret < ret) {
                ret = vret;
            }
        }

        b2Array[value] = b1Array[value];
        b1Array[value] = i;
    }

    return ret == INT_MAX ? -1 : ret;
}