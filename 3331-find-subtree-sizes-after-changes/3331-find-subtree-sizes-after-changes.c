/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int dp (int node, char* s, int* head, int* next, int* ret, int* letters) {
    int c = s[node] - 'a';
    int above = letters[c];
    letters[c] = node;

    for (int child = head[node]; child != -1; child = next[child]) {
        int x = dp(child, s, head, next, ret, letters);
        ret[node] += x;
    }

    letters[c] = above;

    if (above != -1) {
        ret[above] += ret[node];
        return 0;
    }
    else {
        return ret[node];
    }
}

int* findSubtreeSizes(int* parent, int parentSize, char* s, int* returnSize) {
    int n = parentSize;
    int* head = malloc(sizeof(int) * n);
    int* next = malloc(sizeof(int) * n);
    int* ret  = malloc(sizeof(int) * n);

    int letters[26];

    for (int i = 0; i < n; i++) {
        head[i] = -1;
        ret[i] = 1;
    }

    for (int i = 0; i < 26; i++) {
        letters[i] = -1;
    }

    for (int i = 1; i < n; i++) {
        next[i] = head[parent[i]];
        head[parent[i]] = i;
    }

    dp(0, s, head, next, ret, letters);

    free(head);
    free(next);

    *returnSize = n;
    return ret;
}