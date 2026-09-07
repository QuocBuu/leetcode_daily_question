#define MOD (1000000007)
int distinctSubseqII(char* s) {
    int len = strlen(s);
    int arr[26] = {0};
    int ret = 0;
    for (int i = 0; i < len; i++) {
        int c = s[i] - 'a';
        int add = (ret - arr[c] + MOD) % MOD;
        arr[c] = 1 + ret;
        ret = (add + arr[c]) % MOD;
    }

    // for (int i = 0; i < 26; i++) {
    //     printf("[%c] - %d\n", 'a' + i, arr[i]);
    // }

    return ret;
}