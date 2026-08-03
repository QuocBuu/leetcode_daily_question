char* stoneGameIII(int* stoneValue, int stoneValueSize) {
    int ret = 0;

    if (stoneValueSize == 1) {
        ret = stoneValue[0];
    }
    else if (stoneValueSize >= 2) {
        int maxDiffs[3] = {
            stoneValue[stoneValueSize - 2] + abs(stoneValue[stoneValueSize - 1]),
            stoneValue[stoneValueSize - 1],
            0
        };

        for (int i = stoneValueSize - 3; i >= 0; i--) {
            int maxDiff = INT_MIN;
            int sum = 0;

            for (int j = 0; j < 3; j++) {
                sum += stoneValue[i + j];
                int curDiff = sum - maxDiffs[j];
                if (curDiff > maxDiff) {
                    maxDiff = curDiff;
                }
            }

            maxDiffs[2] = maxDiffs[1];
            maxDiffs[1] = maxDiffs[0];
            maxDiffs[0] = maxDiff;
        }

        ret = maxDiffs[0];
    } 

    if (ret > 0) {
        return "Alice";
    }
    else if (ret < 0) {
        return "Bob";
    }
    else {
        return "Tie";
    }
}