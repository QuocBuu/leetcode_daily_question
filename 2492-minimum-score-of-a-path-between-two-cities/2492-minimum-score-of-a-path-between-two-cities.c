int find(int *root, int size, int road) {
    if (size <= road) {
        return -1;
    }
    if (root[road] == road) {
        return road;
    }
    
    root[road] = find(root, size, root[road]);
    return root[road];
}

int minScore(int n, int** roads, int roadsSize, int* roadsColSize) {
    int ret = INT_MAX;
    int rootSize = n + 1;
    int *root = malloc(rootSize * sizeof(int));

    for (int i = 0; i < rootSize; i++) {
        root[i] = i;
    }

    for (int i = 0; i < roadsSize; i++) {
        root[find(root, rootSize, roads[i][0])] = find(root, rootSize, roads[i][1]);
    }

    for (int i = 0; i < roadsSize; i++) {
        if (find(root, rootSize, roads[i][0]) == find(root, rootSize, 1)) {
            ret = ret < roads[i][2] ? ret : roads[i][2]; 
        }
    }

    free(root);
    return ret;
}