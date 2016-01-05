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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode *> que;
        que.push(root);
        while(!que.empty()) {
            queue<TreeNode *> tmp;;
            vector<int> level;

            while (!que.empty()) {
                TreeNode *front = que.front();
                que.pop();
                level.push_back(front->val);
                if (front->left) tmp.push(front->left);
                if (front->right) tmp.push(front->right);
            }
            que = tmp;
            result.push_back(level);
        }
        return result;
    }
};
