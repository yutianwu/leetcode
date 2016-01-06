/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        connect(root, NULL);
    }

    void connect(TreeLinkNode *root, TreeLinkNode *next) {
        if (!root) return;
        root->next = next;
        if (root->left && root->right) {
            connect(root->left, root->right);
            TreeLinkNode *rightNext = (next ? next->left : NULL);
            connect(root->right, rightNext);
        }
    }
};
