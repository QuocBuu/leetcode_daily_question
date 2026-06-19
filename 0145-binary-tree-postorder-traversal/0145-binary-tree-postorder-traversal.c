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
void bfs(int *arr, struct TreeNode *root, int *size) {
    if (root == NULL) {
        return;
    }

    bfs (arr, root->left, size);
    bfs (arr, root->right, size);

    arr[(*size)++] = root->val;
}


int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int *ret = malloc(sizeof(int) * 100);
    
    int size = 0;

    bfs (ret, root, &size);

    *returnSize = size;

    return ret;
}