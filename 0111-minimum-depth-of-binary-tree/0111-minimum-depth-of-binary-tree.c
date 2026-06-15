/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int dfs(struct TreeNode* root, int deep) {
    if (root == NULL) {
        printf("deep %d\n", deep);
        return deep;
    }

    deep++;

    if (root->left == NULL && root->right == NULL) {
        return deep;
    }

    int left = INT_MAX;
    int right = INT_MAX;
    if (root->left != NULL) {
        left = dfs(root->left, deep);
    }
    if (root->right != NULL) {
        right = dfs(root->right, deep);
    }

    return left < right ? left : right;
}

int minDepth(struct TreeNode* root) {
    int ret = dfs(root, 0);

    return ret;
}