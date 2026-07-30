int cmp (const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

int minimumPushes(char* word) {
    #define NUM_CHAR (26)
    int len = strlen(word);
    int arr[NUM_CHAR] = {0};

    for (int i = 0; i < len; i++) {
        arr[word[i] - 'a']++;
    }

    qsort(arr, NUM_CHAR, sizeof(int), cmp);

    int ret = 0;
    for (int i = 0; i < NUM_CHAR; i++) {
        int cnt = (1 + (i / 8));
        ret += arr[i] * cnt;
        if (arr[i] == 0) {
            break;
        }
        // printf("%d - %d - %c\n", ret, cnt, i + 'a');
    }

    return ret;
}