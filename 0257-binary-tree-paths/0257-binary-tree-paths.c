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
int addString (char* path, int len, int val) {
    if (len == 0) {
        len += sprintf(path, "%d", val);
    }
    else {
        len += sprintf(path + len, "->%d", val);
    }
    return len;
}

void dfs (char ***ret, struct TreeNode* root, char* path, int len, int* size) {
    if (root == NULL) {
        return;
    }

    int oldLen = len;
    len = addString(path, len, (int)root->val);

    if (root->left == NULL && root->right == NULL) {
        (*ret)[*size] = strdup(path);
        (*size)++;
        path[oldLen] = '\0';
    }


    dfs (ret, root->left , path, len, size);
    dfs (ret, root->right, path, len, size);

    path[oldLen] = '\0';
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    char **ret = malloc(sizeof(char*) * 100);
    int size = 0;

    char path[1024] = "";
    dfs (&ret, root, path, 0, &size);

    *returnSize = size;

    return ret;
}