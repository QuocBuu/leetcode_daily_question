#define MIN_QUEUE_SIZE 64

typedef struct Element {
    long long data[2];
} Element;

typedef bool (*compare)(const void*, const void*);

typedef struct PriorityQueue {
    Element* arr;
    int capacity;
    int queueSize;
    compare lessFunc;
} PriorityQueue;

static void memswap(void* m1, void* m2, size_t size) {
    unsigned char* a = (unsigned char*)m1;
    unsigned char* b = (unsigned char*)m2;
    while (size--) {
        *b ^= *a ^= *b ^= *a;
        a++;
        b++;
    }
}

static void swap(Element* arr, int i, int j) {
    memswap(&arr[i], &arr[j], sizeof(Element));
}

static void down(Element* arr, int size, int i, compare cmpFunc) {
    for (int k = 2 * i + 1; k < size; k = 2 * k + 1) {
        if (k + 1 < size && cmpFunc(&arr[k], &arr[k + 1])) {
            k++;
        }
        if (cmpFunc(&arr[k], &arr[(k - 1) / 2])) {
            break;
        }
        swap(arr, k, (k - 1) / 2);
    }
}

PriorityQueue* createPriorityQueue(compare cmpFunc) {
    PriorityQueue* obj = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    obj->capacity = MIN_QUEUE_SIZE;
    obj->arr = (Element*)malloc(sizeof(Element) * obj->capacity);
    obj->queueSize = 0;
    obj->lessFunc = cmpFunc;
    return obj;
}

void enQueue(PriorityQueue* obj, Element* e) {
    if (obj->queueSize == obj->capacity) {
        obj->capacity *= 2;
        obj->arr = (Element*)realloc(obj->arr, sizeof(Element) * obj->capacity);
    }
    memcpy(&obj->arr[obj->queueSize], e, sizeof(Element));
    for (int i = obj->queueSize;
         i > 0 && obj->lessFunc(&obj->arr[(i - 1) / 2], &obj->arr[i]);
         i = (i - 1) / 2) {
        swap(obj->arr, i, (i - 1) / 2);
    }
    obj->queueSize++;
}

bool deQueue(PriorityQueue* obj, Element* out) {
    if (obj->queueSize == 0) {
        return false;
    }
    memcpy(out, &obj->arr[0], sizeof(Element));
    swap(obj->arr, 0, obj->queueSize - 1);
    down(obj->arr, obj->queueSize - 1, 0, obj->lessFunc);
    obj->queueSize--;
    return true;
}

bool isEmpty(const PriorityQueue* obj) { return obj->queueSize == 0; }

bool front(const PriorityQueue* obj, Element* out) {
    if (obj->queueSize == 0) {
        return false;
    }
    memcpy(out, &obj->arr[0], sizeof(Element));
    return true;
}

void freeQueue(PriorityQueue* obj) {
    free(obj->arr);
    free(obj);
}

static bool idleLess(const void* a, const void* b) {
    Element* e1 = (Element*)a;
    Element* e2 = (Element*)b;
    if (e1->data[0] != e2->data[0]) {
        return e1->data[0] > e2->data[0];
    }
    return e1->data[1] > e2->data[1];
}

static bool busyLess(const void* a, const void* b) {
    Element* e1 = (Element*)a;
    Element* e2 = (Element*)b;
    if (e1->data[0] != e2->data[0]) {
        return e1->data[0] > e2->data[0];
    }
    return e1->data[1] > e2->data[1];
}

// Move servers with t<=ts from priority queue busy to priority queue idle one
// by one
static void releaseCompleted(PriorityQueue* busy, PriorityQueue* idle,
                             int* servers, long long currentTime) {
    Element frontElem;
    while (!isEmpty(busy)) {
        front(busy, &frontElem);
        if (frontElem.data[0] > currentTime) {
            break;
        }
        deQueue(busy, &frontElem);
        int idx = (int)frontElem.data[1];
        Element idleElem;
        idleElem.data[0] = servers[idx];
        idleElem.data[1] = idx;
        enQueue(idle, &idleElem);
    }
}

int* assignTasks(int* servers, int serversSize, int* tasks, int tasksSize,
                 int* returnSize) {
    int* ans = (int*)malloc(sizeof(int) * tasksSize);
    *returnSize = tasksSize;

    // Idle servers, stored as pairs (w, idx)
    PriorityQueue* idle = createPriorityQueue(idleLess);
    for (int i = 0; i < serversSize; i++) {
        Element e;
        e.data[0] = servers[i];
        e.data[1] = i;
        enQueue(idle, &e);
    }

    // Busy servers, stored as pairs (t, idx)
    PriorityQueue* busy = createPriorityQueue(busyLess);
    long long currentTime = 0;

    for (int i = 0; i < tasksSize; i++) {
        if (currentTime < i) {
            currentTime = i;
        }

        releaseCompleted(busy, idle, servers, currentTime);

        Element frontElem;
        if (isEmpty(idle)) {
            front(busy, &frontElem);
            currentTime = frontElem.data[0];
            releaseCompleted(busy, idle, servers, currentTime);
        }

        Element selected;
        deQueue(idle, &selected);
        int serverIdx = (int)selected.data[1];
        ans[i] = serverIdx;

        Element busyElem;
        busyElem.data[0] = currentTime + tasks[i];
        busyElem.data[1] = serverIdx;
        enQueue(busy, &busyElem);
    }

    freeQueue(idle);
    freeQueue(busy);

    return ans;
}