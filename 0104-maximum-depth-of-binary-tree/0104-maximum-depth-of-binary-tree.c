/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    if (!root->left && !root->right) {
        return 1;
    }

    int maxLeft = 1;
    maxLeft += maxDepth(root->left);
    int maxRight = 1;
    maxRight += maxDepth(root->right);

    return maxLeft > maxRight ? maxLeft : maxRight;
}