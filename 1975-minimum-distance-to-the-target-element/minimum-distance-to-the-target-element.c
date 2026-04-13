int getMinDistance(int* nums, int numsSize, int target, int start) {
    for (int i = 0; i < numsSize; i++) {
        int left = start - i; 
        int right = start + i;

        if (left >= 0 && nums[left] == target) {
            return i;
        }
        
        if (right < numsSize && nums[right] == target) {
            return i;
        }
    }

    return -1;
}