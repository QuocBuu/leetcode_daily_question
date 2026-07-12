#define MAX_N 51

void dfs(int** arr, int n, int val, int* visited, int* vertexCount, int* degreeSum) {
    visited[val] = 1;
    (*vertexCount)++;

    for (int i = 0; i < n; i++) {
        if (arr[val][i]) {
            (*degreeSum)++;

            if (!visited[i]) {
                dfs(arr, n, i, visited, vertexCount, degreeSum);
            }
        }
    }
}

int countCompleteComponents(int n, int** edges, int edgesSize, int* edgesColSize) {
    int** arr = malloc(sizeof(int*) * n);

    for (int i = 0; i < n; i++) {
        arr[i] = calloc(n, sizeof(int));
    }

    for (int i = 0; i < edgesSize; i++) {
        int a = edges[i][0];
        int b = edges[i][1];

        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    int visited[MAX_N] = {0};
    int ret = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int vertexCount = 0;
            int degreeSum = 0;

            dfs(arr, n, i, visited, &vertexCount, &degreeSum);
            if (degreeSum == vertexCount * (vertexCount - 1)) {
                ret++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

    return ret;
}