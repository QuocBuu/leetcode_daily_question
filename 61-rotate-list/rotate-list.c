/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }
    
    struct ListNode* tail = head;
    int size = 1;
    
    while (tail->next != NULL) {
        tail = tail->next;
        size++;
    }

    k = k % size;
    if (k == 0) {
        return head;
    }

    tail->next = head;
    tail = head;
    while (++k < size) {
        tail = tail->next;
    }

    head = tail->next;
    tail->next = NULL;
    
    return head;
}