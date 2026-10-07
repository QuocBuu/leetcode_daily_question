char *remove_char(const char *s, int pos)
{
    int len = strlen(s);

    char *out = (char *)malloc(len);

    memcpy(out, s, pos);
    memcpy(out + pos, s + pos + 1, len - pos);

    return out;
}

void backward(char *s, char ***res, int *resSize, int *resCap,
                     int ri, int rj);

void forward(char *s, char ***res, int *resSize, int *resCap,
                    int li, int lj)
{
    int bal = 0;
    int len = strlen(s);

    for (int i = li; i < len; i++) {
        bal += (s[i] == '(') - (s[i] == ')');

        if (bal >= 0)
            continue;

        for (int j = lj; j <= i; j++) {
            if (s[j] == ')' && (j == lj || s[j - 1] != ')')) {
                char *next = remove_char(s, j);

                forward(next, res, resSize, resCap, i, j);

                free(next);
            }
        }

        return;
    }

    backward(s, res, resSize, resCap, len - 1, len - 1);
}

void backward(char *s, char ***res, int *resSize, int *resCap,
                     int ri, int rj)
{
    int bal = 0;

    for (int i = ri; i >= 0; i--) {
        bal += (s[i] == ')') - (s[i] == '(');

        if (bal >= 0)
            continue;

        for (int j = rj; j >= i; j--) {
            if (s[j] == '(' && (j == rj || s[j + 1] != '(')) {
                char *next = remove_char(s, j);

                backward(next, res, resSize, resCap, i - 1, j - 1);

                free(next);
            }
        }

        return;
    }

    if (*resSize >= *resCap) {
        *resCap *= 2;
        *res = (char **)realloc(*res, (*resCap) * sizeof(char *));
    }

    (*res)[*resSize] = (char *)malloc(strlen(s) + 1);
    strcpy((*res)[*resSize], s);
    (*resSize)++;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **removeInvalidParentheses(char *s, int *returnSize)
{
    int capacity = 16;

    char **res = (char **)malloc(capacity * sizeof(char *));
    *returnSize = 0;

    forward(s, &res, returnSize, &capacity, 0, 0);

    return res;
}