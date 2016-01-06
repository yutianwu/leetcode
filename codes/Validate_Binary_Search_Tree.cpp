/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 解法一
// 用这种解法会涉及到INT_MIN和INT_MAX的问题，所以需要用LONG_MIN,LONG_MAX
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }

    bool validate(TreeNode *root, long minVal, long maxVal) {
        if (root == NULL) return true;
        if (root->val <= minVal || root->val >= maxVal) return false;
        return validate(root->left, minVal, root->val) && validate(root->right, root->val, maxVal);
    }
};

// 解法二
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
    bool isValidBST(TreeNode* root) {
        return validate(root, NULL, NULL);
    }

    bool validate(TreeNode *root, TreeNode *minNode, TreeNode *maxNode) {
        if (root == NULL) return true;
        if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val)) return false;
        return validate(root->left, minNode, root) && validate(root->right, root, maxNode);
    }
};

// 解法三
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
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }

    bool validate(TreeNode *root, TreeNode* &pre) {
        if (root == NULL) return true;
        if (!validate(root->left, pre)) return false;
        if (pre != NULL && pre->val >= root->val) return false;
        pre = root;
        return validate(root->right, pre);
    }
};
