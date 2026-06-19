/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void bfs (struct TreeNode** ret, struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    struct TreeNode *new = malloc(sizeof(struct TreeNode));
    new->val = root->val;
    new->left = NULL;
    new->right = NULL;

    *ret = new;

    bfs(&((*ret)->left) , root->right);
    bfs(&((*ret)->right), root->left);
}

struct TreeNode* invertTree(struct TreeNode* root) {
    struct TreeNode *ret = NULL;

    bfs(&ret, root);

    return ret;
}