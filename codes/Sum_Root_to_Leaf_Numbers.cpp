/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sum;
    int sumNumbers(TreeNode* root) {
        sum = 0;
        if (!root) return sum;
        dfs(root, 0);
        return sum;
    }

    void dfs(TreeNode *root, int num) {
        num = num * 10 + root->val;
        if (root->left)
            dfs(root->left, num);
        if (root->right)
            dfs(root->right, num);
        if (!root->left && !root->right)
            sum += num;
    }
};
