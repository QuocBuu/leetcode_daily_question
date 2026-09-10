# Simple code C || Use DFS || Time O(n) - 4ms

# Intuition
For each node, calculate the sum and number of nodes in its subtree. Then compare the subtree average with the node value.

# Approach
1. Use postorder DFS to process left and right subtrees first.
2. Get the count, sum, and valid-node result from both sides.
3. Combine them with the current node.
4. Compute the integer average using `sum / count`.
5. Increase the result if the average equals the current node value.

# Complexity
- Time complexity: $$O(n)$$
- Space complexity: $$O(n)$$

# Code
```c []
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dp (struct TreeNode* root, int* cnt, int* sum, int* ret) {
    if (root == NULL) {
        return;    
    }

    int cntR = 0;
    int sumR = 0;
    int retR = 0;
    if (root->right != NULL) {
        dp(root->right, &cntR, &sumR, &retR);
    }

    int cntL = 0;
    int sumL = 0;
    int retL = 0;
    if (root->left != NULL) {
        dp(root->left, &cntL, &sumL, &retL);
    }

    *cnt = cntR + cntL + 1;
    *sum = sumR + sumL + root->val;
    *ret = retR + retL + ((*sum) / (*cnt) == root->val ? 1 : 0);
    // printf("[%d] cnt: %d\t sum: %d\t ret: %d\n", root->val, *cnt, *sum, *ret);
}

int averageOfSubtree(struct TreeNode* root) {
    int ret = 0;
    int sum = 0;
    int cnt = 0;
    dp(root, &cnt, &sum, &ret);
    return ret;
}
```
![3bdfd5ea5ba0dbfe82b1.jpg](https://assets.leetcode.com/users/images/8eb1673e-d380-4aa2-8e49-286afdb7814a_1789056660.7024.jpeg)
![bb7c447aca304a6e1321.jpg](https://assets.leetcode.com/users/images/beaa5baa-b25a-421a-a5cb-592b8ef9b68d_1789056667.1969488.jpeg)
