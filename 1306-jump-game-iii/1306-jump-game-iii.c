bool canReach(int* arr, int arrSize, int start) {
    int *array = malloc(arrSize * sizeof(int));
    memset(array, 0, arrSize * sizeof(int));
    int zeroIn = -1;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == 0) {
            zeroIn = i;
            array[i] = 1;
        }
    }

    if (zeroIn == -1) {
        free(array);
        return false;
    }

    for (int i = 0; i < arrSize; i++) {
        int isLoop = false;
        for (int offset = 0; offset < arrSize; offset++) {
            int j1 = zeroIn - offset;
            int j2 = zeroIn + offset;

            if (j1 >= 0 && array[j1] == 0) {
                int next1 = j1 + arr[j1];
                int next2 = j1 - arr[j1];

                if ((next1 >= 0 && next1 < arrSize && array[next1] == 1) ||
                    (next2 >= 0 && next2 < arrSize && array[next2] == 1)) {
                    array[j1] = 1;
                    isLoop = true;
                }
            }

            if (j2 < arrSize && j2 != j1 && array[j2] == 0) {
                int next1 = j2 + arr[j2];
                int next2 = j2 - arr[j2];

                if ((next1 >= 0 && next1 < arrSize && array[next1] == 1) ||
                    (next2 >= 0 && next2 < arrSize && array[next2] == 1)) {
                    array[j2] = 1;
                    isLoop = true;
                }
            }
        }

        if (!isLoop) {
            break;
        }
    }

    if (array[start] == 1) {
        free(array);
        return true;
    }

    free(array);
    return false;
}