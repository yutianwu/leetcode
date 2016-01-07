// 想法真是太巧妙了，先判断是否为完美二叉树，如果是，直接返回节点个数，不是，再往下计算

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
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int hl = 0, hr = 0;
        TreeNode *left = root, *right = root;
        while (left) {
            hl++;
            left = left->left;
        }
        while (right) {
            hr++;
            right = right->right;
        }
        if (hl == hr) return pow(2, hr) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
