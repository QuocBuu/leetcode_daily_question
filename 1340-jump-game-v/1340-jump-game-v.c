int maxJumps(int* arr, int arrSize, int d) {
    int* jumps = malloc(sizeof(int) * arrSize);
    int* stack = malloc(sizeof(int) * arrSize);
    int* drop  = malloc(sizeof(int) * arrSize);

    for (int i = 0; i < arrSize; i++) {
        jumps[i] = 1;
    }

    int stack_count = 0;

    for (int i = 0; i <= arrSize; i++) {
        
        while (stack_count > 0 && (i == arrSize || arr[stack[stack_count-1]] < arr[i])) {
            int dropSize = 0;
            drop[dropSize++] = stack[--stack_count];

            while (stack_count > 0 && (arr[stack[stack_count-1]] == arr[drop[0]])) {
                drop[dropSize++] = stack[--stack_count];
            }

            for (int j = 0; j < dropSize; j++) {
                int k = drop[j];

                if ((i < arrSize) && ((i - k) <= d)) {
                    int val = jumps[k] + 1;
                    if (val > jumps[i]) {
                        jumps[i] = val;
                    }
                }

                if (stack_count > 0 && (k - stack[stack_count - 1]) <= d) {
                    int left = stack[stack_count - 1];
                    int val = jumps[k] + 1;
                    if (val > jumps[left]) {
                        jumps[left] = val;
                    }
                }
            }
        }

        if (i < arrSize) {
            // Save data into stack
            stack[stack_count++] = i;
        }
    }

    int ret = 0;
    for (int i = 0; i < arrSize; i++) {
        if (jumps[i] > ret) {
            ret = jumps[i];
        }
    }

    free(jumps);
    free(stack);
    free(drop);
    return ret;
}