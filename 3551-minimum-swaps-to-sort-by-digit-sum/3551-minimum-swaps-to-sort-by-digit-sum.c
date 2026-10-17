
typedef struct {
    int val;
    int sum;
    int index;
} Node;

int digitNums (int val) {
    int ret = 0;
    while (val) {
        ret += val % 10;
        val /= 10;
    }
    return ret;
}

int cmp (const void* a, const void* b) {
    Node* x = (Node*)a;
    Node* y = (Node*)b;

    if (x->sum != y->sum) {
        return x->sum - y->sum;
    }
    return (x->val > y->val) - (x->val < y->val);
}

int minSwaps(int* nums, int numsSize) {
    Node* arr = malloc(sizeof(Node) * numsSize);
    bool* visited = calloc(numsSize, sizeof(bool));

    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].sum = digitNums(nums[i]);
        arr[i].index = i;
    }

    qsort(arr, numsSize, sizeof(Node), cmp);

    int ret = 0;
    for (int i = 0; i < numsSize; i++) {
        if (visited[i] || arr[i].index == i) {
            continue;
        }

        int cnt = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = arr[j].index;
            cnt++;
        }
        ret += cnt - 1;
    }

    free(arr);
    free(visited);
    return ret;
}
