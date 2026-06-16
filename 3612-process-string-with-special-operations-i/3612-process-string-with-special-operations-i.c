void duplicate(char** str, int *size, int len) {
    if (*size == 0) {
        return;
    }

    int newSize = (*size)*2;

    char *newStr = malloc(sizeof(char) * (len+newSize));
    memcpy(newStr, *str, sizeof(char) * (*size));
    memcpy(newStr + (*size), *str, sizeof(char) * (*size));

    *size = newSize;

    char *freeStr = *str;
    free(freeStr);

    *str = newStr;
}

void reverse(char* str, int size) {
    if (!size) {
        return;
    }
    for (int i = 0; i < (size >> 1); i++) {
        // printf("%d[%c] - %d[%c]\n", i, str[i], size - i -1, str[size - i -1]);
        char c = str[i];
        str[i] = str[size - i - 1];
        str[size - i - 1] = c;
    }
}

char* processStr(char* s) {
    int size = 0;
    int len  = strlen(s);
    char *ret = malloc(sizeof(char) * len+1);

    for (int i = 0; i < len; i++) {
        switch (s[i]) {
            case '#': {
                duplicate(&ret, &size, len);
                // printf("#: %.*s - %d\n", size, ret, size);
            } break;
            case '*': {
                if (size) {
                    size--;
                }
                // printf("*: %.*s - %d\n", size, ret, size);
            } break;
            case '%': {
                reverse(ret, size);
                // printf("\%: %.*s - %d\n", size, ret, size);
            } break;
            default: {
                ret[size] = s[i];
                size++;
                // printf("NULL: %.*s - %d\n", size, ret, size);
            } break;
        }
    }

    ret[size] = '\0';
    return ret;
}