int cmp (const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int missingInteger(int* nums, int numsSize) {
    if (numsSize == 1) {
        return nums[0] + 1;
    }
    // Find
    int minSum = 0;
    int maxCnt = 0;

    // for (int i = 0; i < numsSize-1; i++) {
    int i = 0;
        int cnt = 1;
        int valStart = nums[i];
        int sum = valStart;
        for (int j = i+1; j < numsSize; j++) {
            if ((valStart + cnt) == nums[j]) {
                cnt++;
                sum += nums[j];
                if (j == (numsSize-1)) {
                    if (maxCnt < cnt) {
                        minSum = sum;
                        maxCnt = cnt;
                    }
                    else if (maxCnt == cnt && minSum > sum) {
                        minSum = sum;
                    }
                }
            }
            else {
                if (maxCnt < cnt) {
                    minSum = sum;
                    maxCnt = cnt;
                }
                else if (maxCnt == cnt && minSum > sum) {
                    minSum = sum;
                }

                printf("%d - %d\n", i, minSum);
                i = j - 1;
                break;
            }
        }
    // }

    qsort(nums, numsSize, sizeof(int), cmp);

    if (minSum > nums[numsSize-1]) {
      return minSum;  
    }

    for (int i = 0; i < numsSize; i++) {
        if(nums[i] < minSum) {
            continue;
        }
        else if (nums[i] == minSum) {
            minSum++;
        }
        else {
            break;
        }
    }

    return minSum;
}