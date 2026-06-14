/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool dfs (struct TreeNode* a, struct TreeNode* b) {
    if (a == NULL && b == NULL) {
        return true;
    }

    if (a == NULL || b == NULL) {
        return false;
    }

    if (a->val == b->val) {
        return dfs(a->left, b->right) && dfs(a->right, b->left);
    }

    return false;
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    return dfs(root->left, root->right);
}