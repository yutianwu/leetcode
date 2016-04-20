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
        if (root == NULL) return;
        dfs(root);
    }

    TreeNode *dfs(TreeNode *root) {
        if (root == NULL) return NULL;

        TreeNode *left = dfs(root->left);
        TreeNode *right = dfs(root->right);

        TreeNode *result = root;
        if (left != NULL) {
            left->right = root->right;
            root->right = root->left;
            root->left = NULL;
            result = left;
        }

        result = (right ? right : result);
        return result;
    }
};
