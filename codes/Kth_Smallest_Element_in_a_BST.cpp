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
    int kthSmallest(TreeNode* root, int k) {
        int cur = 0, result = 0;
        travelBST(root, k, cur, result);
        return result;
    }
    
    bool travelBST(TreeNode *root, int k, int &cur, int &result) {
        if (root == NULL)
            return false;
        if (travelBST(root->left, k, cur, result))
            return true;
            
        cur++;
        if (cur == k) {
            result = root->val;
            return true;
        }
    
        if (travelBST(root->right, k, cur, result))
            return true;
            
        return false;
    }
};