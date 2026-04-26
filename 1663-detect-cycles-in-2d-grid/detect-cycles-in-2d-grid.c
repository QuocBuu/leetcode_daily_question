int find(int x, int* parent) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

bool union_sets(int a, int b, int* parent) {
    int ra = find(a, parent), rb = find(b, parent);
    if (ra == rb) 
        return true;
    parent[ra] = rb;
    return false;
}

bool containsCycle(char** grid, int gridSize, int* gridColSize) {
    int rows = gridSize, cols = gridColSize[0];
    int* parent = (int*)malloc(rows * cols * sizeof(int));
    for (int i = 0; i < rows * cols; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j + 1 < cols && grid[i][j] == grid[i][j + 1]) {
                if (union_sets(i * cols + j, i * cols + j + 1, parent)) {
                    free(parent);
                    return true;
                }
            }
            if (i + 1 < rows && grid[i][j] == grid[i + 1][j]) {
                if (union_sets(i * cols + j, (i + 1) * cols + j, parent)) {
                    free(parent);
                    return true;
                }
            }
        }
    }
    free(parent);
    return false;
}