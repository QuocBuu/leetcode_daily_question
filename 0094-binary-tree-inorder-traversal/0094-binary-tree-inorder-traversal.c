/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void dfs(struct TreeNode* root, int* arr, int *size) {
    if (root == NULL) {
        return;
    }
    dfs(root->left, arr, size);
    arr[(*size)++] = root->val;
    dfs(root->right, arr, size); 
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *ret = (int*) malloc(sizeof(int)*100);
    *returnSize = 0;
    dfs(root, ret, returnSize);
    return ret;
}