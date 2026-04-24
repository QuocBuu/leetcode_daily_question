int furthestDistanceFromOrigin(char* moves) {
    int len = strlen(moves);
    int left = 0;
    int right = 0;
    // int emty = 0;
    for (int i = 0; i < len; i++) {
        if (moves[i] == 'L') {
            left++;
        }
        else if (moves[i] == 'R') {
            right++;
        }
        // else {
        //     emty++;
        // }
    }

    return len - 2*(left > right ? right : left);
}