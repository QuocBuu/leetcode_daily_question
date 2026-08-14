/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct node_t {
    // Left
    char leftChar;
    int leftLen;
    // Right
    char rightChar;
    int rightLen;

    int best;
} node_t;

typedef struct {
    int n;
    node_t* tree;
    char* s;
} segTree;

void pull(segTree* root, int node, int left, int right) {
    int mid = (left + right) >> 1;
    int pLeft = node << 1;
    int pRight = pLeft + 1;

    node_t* parent = &root->tree[node];
    node_t* leftNode = &root->tree[pLeft];
    node_t* rightNode = &root->tree[pRight];

    parent->leftChar = leftNode->leftChar;
    parent->rightChar = rightNode->rightChar;

    parent->leftLen = leftNode->leftLen;
    if (leftNode->leftLen == (mid - left + 1) && 
        leftNode->leftChar == rightNode->leftChar) {
        parent->leftLen += rightNode->leftLen;
    }

    parent->rightLen = rightNode->rightLen;
    if (rightNode->rightLen == (right - mid) &&
        rightNode->rightChar == leftNode->rightChar) {
        parent->rightLen += leftNode->rightLen;
    }

    parent->best = leftNode->best > rightNode->best ? leftNode->best : rightNode->best;
    if (leftNode->rightChar == rightNode->leftChar) {
        int merged = leftNode->rightLen + rightNode->leftLen;
        if (merged > parent->best) {
            parent->best = merged;
        }
    } 
}

void build(segTree* root, int node, int left, int right) {
    // printf("Left(%d) - Right(%d)\n", left, right);
    if (left == right) {
        root->tree[node].leftChar = root->s[left];
        root->tree[node].rightChar = root->s[left];
        root->tree[node].best = 1;
        root->tree[node].leftLen = 1;
        root->tree[node].rightLen = 1;
        return;
    }

    int mid = (left + right) >> 1;
    build(root, node<<1, left, mid);
    build(root, (node<<1) + 1, mid + 1, right);

    // PULL
    pull(root, node, left, right);
}

void update(segTree* root, int node, int left, int right, int pos, char ch) {
    if (left == right) {
        root->tree[node].leftChar = ch;
        root->tree[node].rightChar = ch;
        root->tree[node].leftLen = 1;
        root->tree[node].rightLen = 1;
        root->tree[node].best = 1;
        return;
    }

    int mid = (right + left) >> 1;
    if (pos <= mid) {
        update(root, node<<1, left, mid, pos, ch);
    }
    else {
        update(root, (node<<1) + 1, mid+1, right, pos, ch);
    }
    pull(root, node, left, right);
}

int* longestRepeating(char* s, char* queryCharacters, int* queryIndices, int queryIndicesSize, int* returnSize) {
    int len = strlen(s);
    segTree root;
    root.n = len;
    root.s = s;
    root.tree = malloc(sizeof(node_t) * 4 * len);

    // build tree
    build(&root, 1, 0, len - 1);

    *returnSize = queryIndicesSize;
    int* ret = malloc(sizeof(int) * queryIndicesSize);

    for (int i = 0; i < queryIndicesSize; i++) {
        update(&root, 1, 0, len - 1, queryIndices[i], queryCharacters[i]);
        ret[i] = root.tree[1].best;
    }

    free(root.tree);
    return ret;
}