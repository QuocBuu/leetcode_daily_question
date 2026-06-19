/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int bfs(struct TreeNode* root, int height) {
    if (root == NULL) {
        return height;
    }

    height += 1;

    int left = bfs(root->left, height);
    int right = bfs(root->right, height);

    return left > right ? left : right;
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    int left = bfs(root->left, 0);
    int right = bfs(root->right, 0);

    if (abs(left - right) > 1) {
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}