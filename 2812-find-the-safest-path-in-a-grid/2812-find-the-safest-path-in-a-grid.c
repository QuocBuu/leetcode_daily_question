#include <stdlib.h>

typedef struct node node;

struct node {
    int x;
    int y;
    int ct;
    node *next;
};

int dir[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
};

static node *creator(int x, int y, int ct) {
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->x = x;
    new_node->y = y;
    new_node->ct = ct;
    new_node->next = NULL;

    return new_node;
}

static void push(node **head, node **tail, int x, int y, int ct) {
    node *new_node = creator(x, y, ct);
    if (new_node == NULL) {
        return;
    }

    if (*head == NULL) {
        *head = new_node;
        *tail = new_node;
    } else {
        (*tail)->next = new_node;
        *tail = new_node;
    }
}

static node *pop(node **head, node **tail) {
    if (*head == NULL) {
        return NULL;
    }

    node *ret = *head;
    *head = (*head)->next;

    if (*head == NULL) {
        *tail = NULL;
    }

    ret->next = NULL;
    return ret;
}

static int min_int(int a, int b) {
    return a < b ? a : b;
}

int maximumSafenessFactor(int **grid, int gridSize, int *gridColSize) {
    if (gridSize == 0) {
        return 0;
    }

    int n = gridSize;

    node *head = NULL;
    node *tail = NULL;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                push(&head, &tail, i, j, 0);
            }
        }
    }

    while (head != NULL) {
        node *cur = pop(&head, &tail);

        int x = cur->x;
        int y = cur->y;
        int val = grid[x][y];

        for (int i = 0; i < 4; i++) {
            int x1 = x + dir[i][0];
            int y1 = y + dir[i][1];

            if (x1 >= 0 && y1 >= 0 && x1 < n && y1 < n && grid[x1][y1] == 0) {
                grid[x1][y1] = val + 1;
                push(&head, &tail, x1, y1, 0);
            }
        }

        free(cur);
    }

    int **best = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        best[i] = calloc(n, sizeof(int));
    }

    head = NULL;
    tail = NULL;

    best[0][0] = grid[0][0];
    push(&head, &tail, 0, 0, best[0][0]);

    while (head != NULL) {
        node *cur = pop(&head, &tail);

        int x = cur->x;
        int y = cur->y;
        int ct = cur->ct;

        if (ct < best[x][y]) {
            free(cur);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int x1 = x + dir[i][0];
            int y1 = y + dir[i][1];

            if (x1 >= 0 && y1 >= 0 && x1 < n && y1 < n) {
                int next_ct = min_int(ct, grid[x1][y1]);

                if (next_ct > best[x1][y1]) {
                    best[x1][y1] = next_ct;
                    push(&head, &tail, x1, y1, next_ct);
                }
            }
        }

        free(cur);
    }

    int ret = best[n - 1][n - 1] - 1;

    for (int i = 0; i < n; i++) {
        free(best[i]);
    }
    free(best);

    return ret;
}