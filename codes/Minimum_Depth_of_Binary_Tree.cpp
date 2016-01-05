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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return helper(root, 0);
    }
    int helper(TreeNode *p, int pre) {
        pre += 1;
        if (!p->left && !p->right) return pre;
        return min(p->left ? helper(p->left, pre) : INT_MAX, p->right ? helper(p->right, pre) : INT_MAX);
    }
};
