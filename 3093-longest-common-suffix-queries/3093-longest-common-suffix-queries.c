/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct TrieNode {
    struct TrieNode* children[26];
    int best;
    int len;
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->best = -1;
    node->len = INT_MAX;
    for (int i = 0; i < 26; i++) 
        node->children[i] = NULL;
    return node;
}

void insert(TrieNode* root, int idx, const char* word, int len) {
    TrieNode* curr = root;
    for (int i = len - 1; i >= 0; i--) {
        int c = word[i] - 'a';
        if (!curr->children[c]) 
            curr->children[c] = createNode();
        curr = curr->children[c];
        if (curr->best == -1 || len < curr->len) {
            curr->best = idx;
            curr->len = len;
        }
    }
}

int search(TrieNode* root, const char* word, int len) {
    TrieNode* curr = root;
    int lastBest = -1;
    for (int i = len - 1; i >= 0; i--) {
        int c = word[i] - 'a';
        if (!curr->children[c]) 
            break;
        curr = curr->children[c];
        lastBest = curr->best;
    }
    return lastBest;
}

void freeTrie(TrieNode* root) {
    for (int i = 0; i < 26; i++) {
        if (root->children[i]) 
            freeTrie(root->children[i]);
    }
    free(root);
}

int* stringIndices(char** wordsContainer, int wordsContainerSize, char** wordsQuery, int wordsQuerySize, int* returnSize) {
    TrieNode* root = createNode();
    int minLenIdx = 0;

    for (int i = 0; i < wordsContainerSize; i++) {
        int len = strlen(wordsContainer[i]);
        insert(root, i, wordsContainer[i], len);
        if (len < strlen(wordsContainer[minLenIdx])) 
            minLenIdx = i;
    }

    *returnSize = wordsQuerySize;
    int* result = (int*)malloc(sizeof(int) * wordsQuerySize);

    for (int i = 0; i < wordsQuerySize; i++) {
        int len = strlen(wordsQuery[i]);
        int idx = search(root, wordsQuery[i], len);
        result[i] = (idx == -1) ? minLenIdx : idx;
    }

    freeTrie(root);
    return result;
}