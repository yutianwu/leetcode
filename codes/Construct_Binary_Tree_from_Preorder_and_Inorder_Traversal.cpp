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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1);
    }
    TreeNode *buildTree(vector<int> &inorder, int is, int ie, vector<int> &preorder, int ps, int pe) {
        if (is > ie || ps > pe)  return NULL;

        TreeNode *root = new TreeNode(preorder[ps]);
        int left = is;
        for (left; left <= ie; left++) {
            if (inorder[left] == preorder[ps])
                break;
        }
        root->left = buildTree(inorder, is, left - 1, preorder, ps + 1, ps + left - is);
        root->right = buildTree(inorder, left + 1, ie, preorder, ps + left - is + 1, pe);
        return root;
    }
};
