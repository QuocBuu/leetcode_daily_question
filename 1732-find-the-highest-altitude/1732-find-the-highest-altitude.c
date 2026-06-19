int largestAltitude(int* gain, int gainSize) {
    int ret = 0;
    int k = 0;
    for (int i = 0; i < gainSize; i++) {
        k += gain[i];
        if (k > ret) {
            ret = k;
        }
    }
    return ret;
}