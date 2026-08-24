/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

enum {
    NODE_FALSE,
    NODE_TRUE,
    NODE_OR,
    NODE_AND,
};

bool dp (struct TreeNode* root) {
    // printf("Val: %d\n", root->val);
    bool left;
    bool right;
    if (root->left != NULL) {
        left = dp(root->left);
    }

    if (root->right != NULL) {
        right = dp(root->right);
    }

    switch (root->val) {
        case NODE_FALSE:
        case NODE_TRUE: {
            return root->val;
        }
        case NODE_OR: {
            return left | right;
        }
        case NODE_AND: {
            return left & right;
        }
    }

    return false;
}

bool evaluateTree(struct TreeNode* root) {
    if (root == NULL) {
        return false;
    }

    return dp(root);
}