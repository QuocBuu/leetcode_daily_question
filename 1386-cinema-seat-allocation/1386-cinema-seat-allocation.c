int cmp(const void* a, const void* b) {
    int* arrA = *(int**)a;
    int* arrB = *(int**)b;

    if (arrA[0] == arrB[0]) {
        return arrA[1] - arrB[1];
    }

    return arrA[0] - arrB[0];
}

int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize) {
    qsort(reservedSeats, reservedSeatsSize, sizeof(int*), cmp);
#if 0
    for (int i = 0; i < reservedSeatsSize; i++) {
        printf("C %d - %d\n", reservedSeats[i][0], reservedSeats[i][1]);
    }
#endif

    int ret = n * 2;
    for (int i = 0; i < reservedSeatsSize; ) {
        int row = reservedSeats[i][0];
        int arr[11] = {0};
        ret -= 2;

        while (i < reservedSeatsSize && reservedSeats[i][0] == row) {
            arr[reservedSeats[i][1]] = 1;
            i++;
        }

        int left = !arr[2] && !arr[3] && !arr[4] && !arr[5];
        int right = !arr[6] && !arr[7] && !arr[8] && !arr[9];
        int bottom = !arr[4] && !arr[5] && !arr[6] && !arr[7];
        if (left && right) {
            ret += 2;
        }
        else if (left || right || bottom) {
            ret += 1;
        }
    }

    return ret;
}