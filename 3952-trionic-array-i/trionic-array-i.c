bool isTrionic(int* nums, int numsSize) {
    if (numsSize < 4) {
        return false;
    }

    int i = 0;
    while ((i + 1) < numsSize && nums[i] < nums[i+1]) {
        i++;
    }

    if (i == 0) {
        return false;
    }

    int p = i;
    while ((i + 1) < numsSize && nums[i] > nums[i+1]) {
        i++;
    }

    if (i == p) {
        return false;
    }

    int q = i;
    while ((i + 1) < numsSize && nums[i] < nums[i+1]) {
        i++;
    }

    if (i == q || i < (numsSize-1)) {
        return false;
    }

    return true;
}