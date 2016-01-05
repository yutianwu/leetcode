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
    int maxDepth(TreeNode* root) {
        return helper(root, 0);
    }
    int helper(TreeNode *p, int pre) {
        if (!p) return pre;
        pre += 1;
        return max(helper(p->left, pre), helper(p->right, pre));
    }
};
