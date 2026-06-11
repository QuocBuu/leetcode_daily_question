typedef struct node {
    int val;
    struct node* next;
} node;

void addNode(node** tree, int u, int v) {
    node* new = malloc(sizeof(node));
    new->val = v;
    new->next = tree[u];
    tree[u] = new;
}

int dfs(int val, int prev, node** tree) {
    int dist = 0;
    for (node* cur = tree[val]; cur != NULL; cur = cur->next) {
        int c = cur->val;
        if (c != prev) {
            int child = dfs(c, val, tree) + 1;
            if (child > dist) {
                dist = child;
            }
        }
    }

    return dist;
}

long long modPow(long long a, long long b) {

    #define MOD 1000000007
    long long ret = 1;

    while (b > 0) {
        if (b & 1) {
            ret = ret * a % MOD;
        }

        a = a * a % MOD;
        b >>= 1;
    }

    return ret;
}

int assignEdgeWeights(int** edges, int edgesSize, int* edgesColSize) {
    int ret = 0;
    node** tree = calloc(edgesSize + 2, sizeof(node*));
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        addNode(tree, u, v);
        addNode(tree, v, u);
    }

    int d = dfs(1, 0, tree);

    // sum 
    ret = modPow(2, d - 1);
    return ret;
}