/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {

    if(head == NULL) {
        return head;
    }

    int size = 0;
    struct ListNode *tail = head;
    while (tail) {
        size++;
        tail = tail->next;
    }

    if (size == 1) {
        free(head);
        return NULL;
    }

    size = size/2 - 1;
    tail = head;
    while (size-- > 0) {
        tail = tail->next;
        // printf("tail = %d\n", tail->val);
    }

    struct ListNode *tail2 = tail->next;
    struct ListNode *tail3 = tail2 == NULL ? NULL : tail2->next;
    tail->next = tail3;
    free(tail2);

    return head;
}