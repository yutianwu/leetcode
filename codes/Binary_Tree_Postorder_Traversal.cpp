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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode *cur = root, *pre = NULL;
        stack<TreeNode *> s;
        while (!s.empty() || cur) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else {
                TreeNode *top = s.top();
                if (!top->right || (pre == top->right)) {
                    result.push_back(top->val);
                    s.pop();
                    pre = top;
                } else if (pre != top->right && top->right)
                    cur = top->right;
            }
        }
        return result;
    }
};
