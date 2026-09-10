/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dp (struct TreeNode* root, int* cnt, int* sum, int* ret) {
    if (root == NULL) {
        return;    
    }

    int cntR = 0;
    int sumR = 0;
    int retR = 0;
    if (root->right != NULL) {
        dp(root->right, &cntR, &sumR, &retR);
    }

    int cntL = 0;
    int sumL = 0;
    int retL = 0;
    if (root->left != NULL) {
        dp(root->left, &cntL, &sumL, &retL);
    }

    *cnt = cntR + cntL + 1;
    *sum = sumR + sumL + root->val;
    *ret = retR + retL + ((*sum) / (*cnt) == root->val ? 1 : 0);
    // printf("[%d] cnt: %d\t sum: %d\t ret: %d\n", root->val, *cnt, *sum, *ret);
}

int averageOfSubtree(struct TreeNode* root) {
    int ret = 0;
    int sum = 0;
    int cnt = 0;
    dp(root, &cnt, &sum, &ret);
    return ret;
}