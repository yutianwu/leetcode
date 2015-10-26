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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode *> que;
        if (root == NULL)
            return result;
        
        que.push(root);
        while (!que.empty()) {
            TreeNode *top = que.front();
            result.push_back(top->val);
            queue<TreeNode *> tmp;
            while (!que.empty()) {
                top = que.front();
                que.pop();
                
                if (top->right != NULL) 
                    tmp.push(top->right);
                if (top->left != NULL)
                    tmp.push(top->left);
            }
            que = tmp;
        }
        return result;
    }
};