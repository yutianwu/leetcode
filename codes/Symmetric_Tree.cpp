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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return isSymmetricHelper(root->left, root->right);
    }
    bool isSymmetricHelper(TreeNode *left, TreeNode *right) {
        if (left == NULL && right == NULL) return true;

        if (left != NULL && right != NULL) {
            if (left->val != right->val) return false;
            return isSymmetricHelper(left->right, right->left) && isSymmetricHelper(left->left, right->right);
        }
        return false;
    }
};
