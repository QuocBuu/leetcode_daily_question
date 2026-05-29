typedef struct trieNode {
    struct trieNode* child[26]; // a -> z 
    int best;
    int len;
} trieNode;

trieNode* createNode() {
    trieNode* node = malloc(sizeof(trieNode));

    node->best = -1;
    node->len = INT_MAX;

    for (int i = 0; i < 26; i++) {
        node->child[i] = NULL;
    }

    return node;
}

void insert(trieNode* root, int idx, const char* word, int len) {
    trieNode *curr = root;

    for (int i = len - 1; i >= 0; i--) {
        int c = word[i] - 'a';
        if (!curr->child[c]) {
            curr->child[c] = createNode();
        }

        curr = curr->child[c];

        if (curr->best == -1 || len < curr->len) {
            curr->best = idx;
            curr->len = len;
        }
    }
}

int search (trieNode *root, const char* word, int len) {
    trieNode* curr = root;
    int lastBest = -1;
    for (int i = len -1; i >= 0; i--) {
        int c = word[i] - 'a';
        if (!curr->child[c]) {
            break;
        }
        curr = curr->child[c];
        lastBest = curr->best;

    }
    return lastBest;
}

void freeNode (trieNode *root) {
    for (int i = 0; i < 26; i++) {
        if (root->child[i]) {
            freeNode (root->child[i]);
        }
    }
    free(root);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* stringIndices(char** wordsContainer, int wordsContainerSize, char** wordsQuery, int wordsQuerySize, int* returnSize) {
    trieNode *root = createNode();
    int minLen = 0;

    for (int i = 0; i < wordsContainerSize; i++) {
        int len = strlen(wordsContainer[i]); 
        insert(root, i, wordsContainer[i], len);

        if (len < strlen(wordsContainer[minLen])) {
            minLen = i;
        }
    }

    *returnSize = wordsQuerySize;
    int *ret = malloc(sizeof(int)* wordsQuerySize);
    
    for (int i = 0; i < wordsQuerySize; i++) {
        int len = strlen(wordsQuery[i]);
        int idx = search(root, wordsQuery[i], len);
        ret[i] = (idx == -1) ? minLen : idx;
    }

    freeNode(root);
    return ret;
}