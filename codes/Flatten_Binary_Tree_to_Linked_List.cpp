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
    void flatten(TreeNode* root) {
        TreeNode *pre = NULL;
        helper(root, pre);
    }
    void helper(TreeNode *root, TreeNode *&pre) {
        if (!root) return;
        helper(root->left, pre);
        TreeNode *right = root->right;
        if (pre && root->left) {
            root->right = root->left;
            pre->right = right;
            root->left = NULL;
        }
        if (!root->right) pre = root;
        helper(right, pre);
    }
};
