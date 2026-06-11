/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum) {
    bool ret = false;

    if (root == NULL) {
        return false;
    }

    int val = targetSum - root->val;
    if (val == 0) {
        if (root->left == NULL && root->right == NULL) {
            return true;
        }
    }
    printf("%d\n", val);
    ret += hasPathSum(root->left, val);
    ret += hasPathSum(root->right, val);

    return ret;
}