int minFinishTime (int *location1 , int* duration1, int size1, int* location2, int* duration2, int size2) {
    int ret1 = INT_MAX;
    for (int i = 0; i < size1; i++) {
        int val = location1[i] + duration1[i];
        ret1 = ret1 < val ? ret1 : val;
    }

    int ret2 = INT_MAX;
    for (int i = 0; i < size2; i++) {
        int val = location2[i] + duration2[i];
        int val2 = ret1 + duration2[i];
        
        val = val > val2 ? val : val2;
        ret2 = ret2 < val ? ret2 : val;
    }

    return ret2;
}

int earliestFinishTime(int* landStartTime, int landStartTimeSize, int* landDuration, int landDurationSize, int* waterStartTime, int waterStartTimeSize, int* waterDuration, int waterDurationSize) {
    int minLand = minFinishTime(landStartTime, landDuration, landStartTimeSize, waterStartTime, waterDuration, waterStartTimeSize);
    int minWater = minFinishTime(waterStartTime, waterDuration, waterStartTimeSize, landStartTime, landDuration, landStartTimeSize);

    return minLand > minWater ? minWater : minLand;
}