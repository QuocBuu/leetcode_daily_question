#define HASH_SIZE 2048
typedef struct node {
    char* key;
    char* value;
    struct node* next;
} node;

uint32_t hash(char* str, int len) {
    uint32_t h = 5381;
    for (int i = 0; i < len; i++) {
        h = ((h << 5) + h) + str[i];
    }

    return h % HASH_SIZE;
}

void insert (node** table, char* key, char* value) {
    int len = strlen(key);
    uint32_t index = hash(key, len);
    node* nodeNew = malloc(sizeof(node));
    nodeNew->key = key;
    nodeNew->value = value;
    nodeNew->next = table[index];

    table[index] = nodeNew;
}

char* find(node** table, char* key, int keyLen) {
    uint32_t index = hash(key, keyLen);
    node* cNode = table[index];
    while (cNode) {
        if (strlen(cNode->key) == keyLen &&
            strncmp(cNode->key, key, keyLen) == 0) {
            return cNode->value;
        }

        cNode = cNode->next;
    }

    return "?";
}


char* evaluate(char* s, char*** knowledge, int knowledgeSize, int* knowledgeColSize) {
    node* table[HASH_SIZE] = {0};

    for (int i = 0; i < knowledgeSize; i++) {
        insert(table, knowledge[i][0], knowledge[i][1]);
    }

    int cap = strlen(s) + 1;
    int len = 0;

    char* ret = malloc(cap);

    for (int i = 0; s[i];) {
        if (s[i] != '(') {
            if (len + 2 > cap) {
                cap *= 2;
                ret = realloc(ret, cap);
            }

            ret[len++] = s[i++];
            continue;
        }

        int start = ++i;

        while (s[i] != ')') {
            i++;
        }

        int keyLen = i - start;

        char* value = find(table, s + start, keyLen);
        int valueLen = strlen(value);

        while (len + valueLen + 1 > cap) {
            cap *= 2;
            ret = realloc(ret, cap);
        }

        memcpy(ret + len, value, valueLen);
        len += valueLen;

        i++;
    }

    ret[len] = '\0';

    for (int i = 0; i < HASH_SIZE; i++) {
        node* cNode = table[i];

        while (cNode) {
            node* next = cNode->next;
            free(cNode);
            cNode = next;
        }
    }

    return ret;
}