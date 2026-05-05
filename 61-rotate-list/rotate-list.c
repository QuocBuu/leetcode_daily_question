/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL) {
        return head;
    }

    if (head->next == NULL) {
        return head;
    }
    
    struct ListNode* tail = head;
    int size = 1;
    
    while (tail->next != NULL) {
        tail = tail->next;
        size++;
    }

    if (k % size == 0) {
        return head;
    }

    int counter = size - (k % size) - 1;

    struct ListNode* tail2 = head;
    while (counter--) {
        tail2 = tail2->next;
    }

    tail->next = head;
    head = tail2->next;
    tail2->next = NULL;
    
    return head;
}