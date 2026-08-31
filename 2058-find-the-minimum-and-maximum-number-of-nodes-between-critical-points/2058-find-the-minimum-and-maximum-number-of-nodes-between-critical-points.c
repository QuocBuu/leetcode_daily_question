/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    *returnSize = 2;
    int* ret = malloc(sizeof(int) * 2);
    ret[0] = ret[1] = -1;

    int min = INT_MAX;
    int node[2] = {-1, -1};
    int listSize = 1;
    int mark = head->val;
    head = head->next;
    while (head->next) {
        listSize++;
        int cur = head->val;
        head = head->next;
        int next = head->val;
        // printf("[%d] %d - %d - %d\n", listSize, mark, cur, next);
        if ((cur < mark && cur < next) || (cur > mark && cur > next)) {
            if (node[0] == -1) {
                node[0] = listSize;
                node[1] = listSize;
            }
            else {
                if (min > (listSize - node[1])) {
                    min = listSize - node[1];
                }
                node[1] = listSize;
            }
        }
        mark = cur;
    }

    if (node[0] == -1 || node[0] == node[1]) {
        return ret;
    }

    ret[0] = min;
    ret[1] = node[1] - node[0];

    // printf("Result: %d - %d\n", ret[0], ret[1]);

    return ret;
}