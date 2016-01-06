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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if (!root) return result;
        vector<int> item;
        helper(root, result, item, 0, sum);
        return result;
    }

    void helper(TreeNode *root, vector<vector<int>> &result, vector<int> &item, int pre, int sum) {
        pre += root->val;
        item.push_back(root->val);
        if (root->left) helper(root->left, result, item, pre, sum);
        if (root->right) helper(root->right, result, item, pre, sum);
        if (!root->left && !root->right) {
            if (pre == sum) result.push_back(item);
        }
        item.pop_back();
    }
};
