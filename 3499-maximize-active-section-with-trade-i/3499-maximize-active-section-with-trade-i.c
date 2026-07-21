int maxActiveSectionsAfterTrade(char* s) {
    int len = strlen(s);

    int start = -1;   
    int end1 = -1;    
    int start2 = -1;  
    int end2 = -1;    

    int max = 0;
    int sum = 0;

    for (int i = 0; i <= len; i++) {
        char current = (i < len) ? s[i] : '1';

        if (current == '1' && i < len) {
            sum++;
            // printf("sum - %d\n", sum);
        }

        if (start == -1) {
            if (current == '0') {
                start = i;
                end1 = -1;
                start2 = -1;
                end2 = -1;

                printf("start - %d\n", start);
            }
        } else {
            if (end1 == -1) {
                if (current == '1') {
                    end1 = i;
                    // printf("end1 - %d\n", end1);
                }
            } else {
                if (current == '0') {
                    if (start2 == -1) {
                        start2 = i;
                    }

                    end2 = i;
                    // printf("end2 - %d\n", end2);
                } else if (start2 != -1) {
                    int leftZeros = end1 - start;
                    int rightZeros = end2 - start2 + 1;
                    int gain = leftZeros + rightZeros;

                    max = max > gain ? max : gain;

                    // printf("leftZeros  - %d\n", leftZeros);
                    // printf("rightZeros - %d\n", rightZeros);
                    // printf("max gain   - %d\n", max);
                    start = start2;
                    end1 = i;
                    start2 = -1;
                    end2 = -1;
                }
            }
        }
    }

    return sum + max;
}