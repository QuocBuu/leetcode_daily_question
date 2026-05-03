bool rotateString(char* s, char* goal) {
    int size1 = strlen(s);
    int size2 = strlen(goal);
    if (size1 != size2) {
        return false;
    }

    char tmp[size1*2 + 1];
    memcpy(tmp, s, size1);
    memcpy(tmp+size1, s, size1 + 1);

    return (strstr(tmp,goal) != NULL);
}