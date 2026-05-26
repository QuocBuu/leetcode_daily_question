/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL && list2 == NULL) {
        return NULL;
    }
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    int val1 = list1->val;
    int val2 = list2->val;
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    while (list1 != NULL || list2 != NULL) {
        // printf("%d - %d\n", val1, val2);
        struct ListNode* tail1 = tail;
        if (val1 > val2) {
            tail = list2;
            if (list2->next == NULL) {
                list2 = NULL;
                val2 = INT_MAX;
            }
            else {
                list2 = list2->next;
                val2 = list2->val;
            }
        }
        else {
            tail = list1;
            if (list1->next == NULL) {
                list1 = NULL;
                val1 = INT_MAX;
            }
            else {
                list1 = list1->next;
                val1 = list1->val;
            }
        }

        if (head == NULL) {
            head = tail;
        }
        
        if (tail1 != NULL) {
            tail1->next = tail;
        }
        // printf("%d\n", tail->val);
    }

    return head;
}