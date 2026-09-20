int countIntersectingIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {

    int ret = 0;

    for (int i = 0; i < intervalsSize; i++) {
        int start1 = intervals[i][0];
        int end1   = intervals[i][1];
        for (int j = i + 1; j < intervalsSize; j++) {
            int start2 = intervals[j][0];
            int end2   = intervals[j][1];

            if (start1 <= end2 && start2 <= end1) {
                ret++;
            }
        }
    }

    return ret;
}