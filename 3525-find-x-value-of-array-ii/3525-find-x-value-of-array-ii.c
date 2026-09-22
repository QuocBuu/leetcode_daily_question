/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXK 6

typedef struct {
    int k;
    int n;
    int* tree;
} SegmentTree;

static inline int* getNode(SegmentTree* seg, int o) {
    return &seg->tree[o * MAXK];
}

static void makeLeaf(SegmentTree* seg, int o, int value) {
    int* node = getNode(seg, o);
    memset(node, 0, MAXK * sizeof(int));
    int r = value % seg->k;
    node[r] = 1;
    node[seg->k] = r;
}

static void mergePre(SegmentTree* seg, int* left, int* right, int* result) {
    int mulL = left[seg->k];
    int mulR = right[seg->k];
    result[seg->k] = (mulL * mulR) % seg->k;

    for (int x = 0; x < seg->k; x++) {
        result[x] = left[x];
    }
    for (int x = 0; x < seg->k; x++) {
        result[(mulL * x) % seg->k] += right[x];
    }
}

static void maintain(SegmentTree* seg, int o) {
    int* left = getNode(seg, o * 2);
    int* right = getNode(seg, o * 2 + 1);
    int* node = getNode(seg, o);
    mergePre(seg, left, right, node);
}

static void build(SegmentTree* seg, int* nums, int o, int l, int r) {
    if (l == r) {
        makeLeaf(seg, o, nums[l]);
        return;
    }
    int m = (l + r) / 2;
    build(seg, nums, o * 2, l, m);
    build(seg, nums, o * 2 + 1, m + 1, r);
    maintain(seg, o);
}

SegmentTree* createSegmentTree(int* nums, int n, int k) {
    SegmentTree* seg = (SegmentTree*)malloc(sizeof(SegmentTree));
    seg->k = k;
    seg->n = n;

    int size = 2 << (int)ceil(log2(n));
    seg->tree = (int*)calloc(size * MAXK, sizeof(int));
    build(seg, nums, 1, 0, n - 1);
    return seg;
}

void destroySegmentTree(SegmentTree* seg) {
    if (seg) {
        free(seg->tree);
        free(seg);
    }
}

void update(SegmentTree* seg, int o, int l, int r, int index, int value) {
    if (l == r) {
        makeLeaf(seg, o, value);
        return;
    }
    int m = (l + r) / 2;
    if (index <= m) {
        update(seg, o * 2, l, m, index, value);
    } else {
        update(seg, o * 2 + 1, m + 1, r, index, value);
    }
    maintain(seg, o);
}

void query(SegmentTree* seg, int o, int l, int r, int L, int R, int* result) {
    if (L <= l && r <= R) {
        int* node = getNode(seg, o);
        memcpy(result, node, MAXK * sizeof(int));
        return;
    }

    int m = (l + r) / 2;
    if (R <= m) {
        query(seg, o * 2, l, m, L, R, result);
        return;
    }
    if (L > m) {
        query(seg, o * 2 + 1, m + 1, r, L, R, result);
        return;
    }

    int left[MAXK];
    int right[MAXK];
    query(seg, o * 2, l, m, L, R, left);
    query(seg, o * 2 + 1, m + 1, r, L, R, right);
    mergePre(seg, left, right, result);
}

int* resultArray(int* nums, int numsSize, int k, int** queries, int queriesSize,
                 int* queriesColSize, int* returnSize) {
    int n = numsSize;
    SegmentTree* seg = createSegmentTree(nums, n, k);
    int* ans = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;

    for (int i = 0; i < queriesSize; i++) {
        int* q = queries[i];
        int index = q[0];
        int value = q[1];
        int start = q[2];
        int x = q[3];

        update(seg, 1, 0, n - 1, index, value);
        int pre[MAXK];
        query(seg, 1, 0, n - 1, start, n - 1, pre);
        ans[i] = pre[x];
    }

    destroySegmentTree(seg);
    return ans;
}