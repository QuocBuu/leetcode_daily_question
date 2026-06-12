/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MOD 1000000007
typedef struct Node {
    int val;
    struct Node* next;
} Node;

void addEdge(Node** adj, int u, int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = v;
    node->next = adj[u];
    adj[u] = node;
}

int lca(int u, int v, int** up, int* depth, int LOG) {
    if (depth[u] < depth[v]) {
        int temp = u;
        u = v;
        v = temp;
    }

    int diff = depth[u] - depth[v];
    for (int k = 0; k < LOG; k++) {
        if ((diff >> k) & 1) {
            u = up[k][u];
        }
    }

    if (u == v) 
        return u;
    for (int k = LOG - 1; k >= 0; k--) {
        if (up[k][u] != up[k][v]) {
            u = up[k][u];
            v = up[k][v];
        }
    }
    return up[0][u];
}

int* assignEdgeWeights(
    int** edges,
    int edgesSize,
    int* edgesColSize,
    int** queries,
    int queriesSize,
    int* queriesColSize,
    int* returnSize

) {
    int n = edgesSize + 1;
    Node** adj = (Node**)calloc(n + 1, sizeof(Node*));

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        addEdge(adj, u, v);
        addEdge(adj, v, u);
    }

    int* depth = (int*)calloc(n + 1, sizeof(int));
    int* parent = (int*)calloc(n + 1, sizeof(int));
    int* visited = (int*)calloc(n + 1, sizeof(int));
    int* queue = (int*)malloc((n + 1) * sizeof(int));
    int front = 0, back = 0;
    queue[back++] = 1;
    visited[1] = 1;

    while (front < back) {
        int node = queue[front++];
        for (Node* cur = adj[node]; cur != NULL; cur = cur->next) {
            int nei = cur->val;
            if (!visited[nei]) {
                visited[nei] = 1;
                depth[nei] = depth[node] + 1;
                parent[nei] = node;
                queue[back++] = nei;
            }
        }
    }

    int LOG = 1;
    while ((1 << LOG) <= n) 
        LOG++;
    int** up = (int**)malloc(LOG * sizeof(int*));
    for (int k = 0; k < LOG; k++) {
        up[k] = (int*)calloc(n + 1, sizeof(int));
    }
    for (int v = 0; v <= n; v++) {
        up[0][v] = parent[v];
    }
    for (int k = 1; k < LOG; k++) {
        for (int v = 0; v <= n; v++) {
            up[k][v] = up[k - 1][up[k - 1][v]];
        }
    }
    int* pow2 = (int*)malloc((n + 1) * sizeof(int));
    pow2[0] = 1;
    for (int i = 1; i <= n; i++) {
        pow2[i] = (long long)pow2[i - 1] * 2 % MOD;
    }
    int* ans = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;
    for (int i = 0; i < queriesSize; i++) {
        int u = queries[i][0];
        int v = queries[i][1];
        int ancestor = lca(u, v, up, depth, LOG);
        int dist = depth[u] + depth[v] - 2 * depth[ancestor];
        ans[i] = dist ? pow2[dist - 1] : 0;
    }
    return ans;
}