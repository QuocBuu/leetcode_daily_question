int earliestFinishTime(int* landStartTime, int landStartTimeSize, int* landDuration, int landDurationSize, int* waterStartTime, int waterStartTimeSize, int* waterDuration, int waterDurationSize) {
    int ret = INT_MAX;

    for (int i = 0; i < landStartTimeSize; i++) {
        for (int j = 0; j < waterStartTimeSize; j++) {
            int val;
            int fLand = landStartTime[i] + landDuration[i];
            if(fLand > waterStartTime[j]) {
                val = fLand + waterDuration[j];
            }
            else {
                val =  waterStartTime[j] + waterDuration[j];
            }

            if (val < ret) {
                ret = val;
            }

            int fWater = waterStartTime[j] + waterDuration[j];
            if (fWater > landStartTime[i]) {
                val = fWater + landDuration[i];
            }
            else {
                val = landStartTime[i] + landDuration[i];
            }

            if (val < ret) {
                ret = val;
            }
        }
    }
    return ret;
}