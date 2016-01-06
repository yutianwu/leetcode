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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *top = s.top();
            s.pop();
            result.push_back(top->val);
            if (top->right) s.push(top->right);
            if (top->left) s.push(top->left);
        }
        return result;
    }
};
