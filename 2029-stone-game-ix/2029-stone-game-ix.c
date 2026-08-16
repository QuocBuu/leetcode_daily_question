bool stoneGameIX(int* stones, int stonesSize) {
    int cnt[3] = {0};
    for (int i = 0; i < stonesSize; i++) {
        cnt[stones[i] % 3]++;
    }

    if (cnt[0] % 2 == 0) {
        return cnt[1] >= 1 && cnt[2] >= 1;
    }

    return abs(cnt[1] - cnt[2]) >= 3;
}