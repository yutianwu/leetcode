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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode *buildTree(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe) {
        if (is > ie || ps > pe)  return NULL;

        TreeNode *root = new TreeNode(postorder[pe]);
        int left = is;
        for (left; left <= ie; left++) {
            if (inorder[left] == postorder[pe])
                break;
        }
        root->left = buildTree(inorder, is, left - 1, postorder, ps, ps + left - is - 1);
        root->right = buildTree(inorder, left + 1, ie, postorder, ps + left - is, pe - 1);
        return root;
    }
};
