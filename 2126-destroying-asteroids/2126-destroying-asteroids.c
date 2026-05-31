int cmp (const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
bool asteroidsDestroyed(int mass, int* asteroids, int asteroidsSize) {
    qsort(asteroids, asteroidsSize, sizeof(int), cmp);
    long long max = mass;
    for (int i = 0; i < asteroidsSize; i++) {
        // printf("%d\n", asteroids[i]);
        if (max < asteroids[i]) {
            return false;
        }
        else {
            max += asteroids[i];
        }
    }

    return true;
}