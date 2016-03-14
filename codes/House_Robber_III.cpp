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
    int rob(TreeNode* root) {
        return dfs(root).second;
    }

    pair<int, int> dfs(TreeNode *root) {
        if (root == NULL) return make_pair(0, 0);

        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);

        int rob = left.second + right.second;
        int notRob = max(rob, left.first + right.first + root->val);
        return make_pair(rob, notRob);
    }
};
