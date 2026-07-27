int maxProduct(int* nums, int numsSize) {
    int max[2] = {INT_MIN, INT_MIN};
    int min[2] = {INT_MAX, INT_MAX};

    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];
        if (val > max[0]) {
            max[1] = max[0];
            max[0] = val;
        }
        else if (val > max[1]) {
            max[1] = val;
        }

        if (val < min[0]) {
            min[1] = min[0];
            min[0] = val;
        }
        else if (val < min[1]) {
            min[1] = val;
        }
    }

    int max1 = (max[0] - 1) * (max[1] - 1);
    int max2 = (min[0] - 1) * (min[1] - 1);

    return max1 > max2 ? max1 : max2; 
}