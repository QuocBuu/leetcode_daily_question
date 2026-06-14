/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void addNode(struct ListNode** tail, int value) {
    struct ListNode* new = malloc(sizeof(struct ListNode));
    new->val = value;
    new->next = *tail;
    *tail = new;
}

void freeNode(struct ListNode** tail) {
    while (*tail) {
        struct ListNode* old = *tail;
        *tail = (*tail)->next;
        free(old);
    }
}

int pairSum(struct ListNode* head) {
    int size = 0;
    struct ListNode* tail = head;
    struct ListNode* newNode = NULL;
    while (tail) {
        addNode(&newNode, tail->val);
        tail = tail->next;
        size++;
    }
    size = (size/2) - 1;

    int ret = INT_MIN;
    for (int i = 0; i <= size; i++) {
        int val = head->val + newNode->val;
        if (val > ret) {
            ret = val;
        }

        head = head->next;
        newNode = newNode->next;
    }
    freeNode(&newNode);
    return ret;
}