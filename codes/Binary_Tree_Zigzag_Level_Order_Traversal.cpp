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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        vector<TreeNode *> que;
        que.push_back(root);
        bool zig = true;
        while (que.size() > 0) {
            vector<int> row;
            vector<TreeNode*> tmp;
            for (int i = 0; i < que.size(); i++) {
                TreeNode *top = que[i];
                if (top->left) tmp.push_back(top->left);
                if (top->right) tmp.push_back(top->right);
            }
            row = helper(que, zig);
            zig = !zig;
            result.push_back(row);
            que = tmp;
        }
        return result;
    }

    vector<int> helper(vector<TreeNode *> &que, bool zig) {
        vector<int> row;
        if (zig) {
            for (int i = 0; i < que.size(); i++) {
                row.push_back(que[i]->val);
            }
        } else {
            for (int i = que.size() - 1; i >= 0; i--) {
                row.push_back(que[i]->val);
            }
         }
         return row;
    }
};
