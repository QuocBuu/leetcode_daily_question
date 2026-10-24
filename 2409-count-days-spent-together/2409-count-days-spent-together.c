int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int totalDays(int month) {
    int ret = 0;
    for (int i = 0; i < month - 1; i++) {
        ret += days[i];
        // printf("%d - ", ret);
    }
    // printf("t - %d\n", ret);
    return ret;
}

int countDaysTogether(char* arriveAlice, char* leaveAlice, char* arriveBob, char* leaveBob) {
    int monAlice_ar = (arriveAlice[0] - '0') * 10 + (arriveAlice[1] - '0');
    int dayAlice_ar = (arriveAlice[3] - '0') * 10 + (arriveAlice[4] - '0') + totalDays(monAlice_ar);
    // printf("%d - %d\n", monAlice_ar, dayAlice_ar);

    int monAlice_le = (leaveAlice[0] - '0') * 10 + (leaveAlice[1] - '0');
    int dayAlice_le = (leaveAlice[3] - '0') * 10 + (leaveAlice[4] - '0') + totalDays(monAlice_le);
    dayAlice_le = dayAlice_le >= dayAlice_ar ? dayAlice_le : dayAlice_le + 365;  
    // printf("%d - %d\n", monAlice_le, dayAlice_le);

    int monBod_ar = (arriveBob[0] - '0') * 10 + (arriveBob[1] - '0');
    int dayBod_ar = (arriveBob[3] - '0') * 10 + (arriveBob[4] - '0') + totalDays(monBod_ar);
    // printf("%d - %d\n", monBod_ar, dayBod_ar);

    int monBod_le = (leaveBob[0] - '0') * 10 + (leaveBob[1] - '0');
    int dayBod_le = (leaveBob[3] - '0') * 10 + (leaveBob[4] - '0') + totalDays(monBod_le);
    dayBod_le = dayBod_le >= dayBod_ar ? dayBod_le : dayBod_le + 365;  
    // printf("%d - %d\n", monBod_le, dayBod_le);

    if (dayAlice_ar > dayBod_le || dayBod_ar > dayAlice_le) {
        return 0;
    }

    int start = dayAlice_ar > dayBod_ar ? dayAlice_ar : dayBod_ar;
    int end   = dayAlice_le < dayBod_le ? dayAlice_le : dayBod_le;

    return end - start + 1;
}