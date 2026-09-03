/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool dp(struct TreeNode* root, long long max, long long min) {
    if (root == NULL) {
        return true;
    }

    if (root->val <= min || root->val >= max) {
        return false;
    }

    return dp(root->left, root->val, min) && dp(root->right, max, root->val);
}

bool isValidBST(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    return dp(root, LLONG_MAX, LLONG_MIN);
}