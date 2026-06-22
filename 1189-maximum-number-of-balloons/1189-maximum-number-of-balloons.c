int maxNumberOfBalloons(char* text) {
    int arr[26] = {0};

    for (int i = 0; i < strlen(text); i++) {
        arr[text[i] - 'a']++;
    }

    char *key = "balloon";
    int ret = INT_MAX;
    
    // b
    int val = arr['b'-'a'];
    if (ret > val) {
        ret = val;
    }

    // a
    val = arr[0];
    if (ret > val) {
        ret = val;
    }

    // l
    val = arr['l'-'a'];
    val >>= 1;
    if (ret > val) {
        ret = val;
    }

    // o
    val = arr['o'-'a'];
    val >>= 1;
    if (ret > val) {
        ret = val;
    }

    // n
    val = arr['n'-'a'];
    if (ret > val) {
        ret = val;
    }

    return ret;
}