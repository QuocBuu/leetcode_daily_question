#define HASH_SIZE 200003

typedef struct Node {
    int val;
    struct Node* next;
} Node;

unsigned int hashKey(int x) {
    return ((unsigned int)x) % HASH_SIZE;
}

bool contains(Node** set, int x) {
    unsigned int h = hashKey(x);
    Node* cur = set[h];

    while (cur) {
        if (cur->val == x)
            return true;

        cur = cur->next;
    }

    return false;
}

void insert(Node** set, int x) {
    if (contains(set, x))
        return;

    unsigned int h = hashKey(x);

    Node* node = (Node*)malloc(sizeof(Node));
    node->val = x;
    node->next = set[h];
    set[h] = node;
}

int digitLen(int x) {
    int len = 0;

    while (x > 0) {
        len++;
        x /= 10;
    }
    return len;
}
int longestCommonPrefix(int* arr1, int arr1Size, int* arr2, int arr2Size) {
    Node** prefix = (Node**)calloc(HASH_SIZE, sizeof(Node*));
    for (int i = 0; i < arr1Size; i++) {
        int a = arr1[i];
        while (a > 0) {
            if (contains(prefix, a))
                break;
            insert(prefix, a);
            a /= 10;
        }
    }
    int res = 0;
    for (int i = 0; i < arr2Size; i++) {
        int b = arr2[i];
        while (b > res) {
            if (contains(prefix, b)) {
                res = b;
                break;
            }
            b /= 10;
        }
    }
   return res ? digitLen(res) : 0;
}