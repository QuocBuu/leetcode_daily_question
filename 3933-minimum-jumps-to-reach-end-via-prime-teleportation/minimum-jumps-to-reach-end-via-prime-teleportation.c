#define MAX_VAL 1000001

typedef struct {
    int* data;
    int size;
    int capacity;
} Vector;

void vector_init(Vector* v) {
    v->size = 0;
    v->capacity = 4;
    v->data = (int*)malloc(sizeof(int) * v->capacity);
}

void vector_push(Vector* v, int val) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int*)realloc(v->data, sizeof(int) * v->capacity);
    }
    v->data[v->size++] = val;
}

void vector_free(Vector* v) {
    free(v->data);
}


typedef struct {
    int* data;
    int head;
    int tail;
} Queue;

int minJumps(int* nums, int numsSize) {
    int n = numsSize;
    if (n <= 1) 
        return 0;

    Vector* port = (Vector*)malloc(sizeof(Vector) * MAX_VAL);
    bool* has_port = (bool*)calloc(MAX_VAL, sizeof(bool));

    for (int i = 0; i < n; i++) {
        int tmp = nums[i];
        for (int d = 2; d * d <= tmp; d++) {
            if (tmp % d == 0) {
                if (!has_port[d]) {
                    vector_init(&port[d]);
                    has_port[d] = true;
                }
                vector_push(&port[d], i);
                while (tmp % d == 0) tmp /= d;
            }
        }
        if (tmp > 1) {
            if (!has_port[tmp]) {
                vector_init(&port[tmp]);
                has_port[tmp] = true;
            }
            vector_push(&port[tmp], i);
        }
    }

    bool* visited = (bool*)calloc(n, sizeof(bool));
    Queue q;
    q.data = (int*)malloc(sizeof(int) * n);
    q.head = 0;
    q.tail = 0;

    q.data[q.tail++] = 0;
    visited[0] = true;
    int steps = 0;

    while (q.head < q.tail) {
        int size = q.tail - q.head;
        while (size--) {
            int i = q.data[q.head++];
            if (i == n - 1) {
                for (int j = 0; j < MAX_VAL; j++) {
                    if (has_port[j]) 
                        vector_free(&port[j]);
                }
                free(port); free(has_port); free(visited); free(q.data);
                return steps;
            }

            int num = nums[i];

            if (num < MAX_VAL && has_port[num]) {
                for (int k = 0; k < port[num].size; k++) {
                    int nei = port[num].data[k];
                    if (!visited[nei]) {
                        visited[nei] = true;
                        q.data[q.tail++] = nei;
                    }
                }

                vector_free(&port[num]);
                has_port[num] = false;
            }

            if (i + 1 < n && !visited[i + 1]) {
                visited[i + 1] = true;
                q.data[q.tail++] = i + 1;
            }

            if (i - 1 >= 0 && !visited[i - 1]) {
                visited[i - 1] = true;
                q.data[q.tail++] = i - 1;
            }
        }
        steps++;
    }

    return -1;
}