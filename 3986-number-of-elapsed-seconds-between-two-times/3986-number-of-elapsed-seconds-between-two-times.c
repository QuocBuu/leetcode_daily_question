int seconds (const char *time) {
    int hh = (time[0] - '0') * 10 + time[1] - '0';
    int mm = (time[3] - '0') * 10 + time[4] - '0';
    int ss = (time[6] - '0') * 10 + time[7] - '0';

    return hh * 3600 + mm * 60 + ss;
}

int secondsBetweenTimes(char* startTime, char* endTime) {
    int start = seconds(startTime);
    int end   = seconds(endTime);

    if (end < start) {
        end += 24 * 60 * 60;
    }

    return end - start;
}