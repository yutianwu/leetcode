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
private:
    int total;
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;

        total = sum;
        return helper(root, 0);
    }

    bool helper(TreeNode *p, int pre) {
        pre += p->val;
        if (!p->left && !p->right && pre == total) return true;
        return (p->left ? helper(p->left, pre) : 0)  || (p->right ? helper(p->right, pre) : 0);
    }
};
