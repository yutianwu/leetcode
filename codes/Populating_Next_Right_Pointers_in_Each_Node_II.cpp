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
        TreeLinkNode *cur = new TreeLinkNode(0);
        cur->next = root;
        while (cur->next) {
            TreeLinkNode *dummy = new TreeLinkNode(0);
            TreeLinkNode *next = dummy;
            while (cur->next) {
                TreeLinkNode *visit = cur->next;
                if (visit->left) {
                    next->next = visit->left;
                    next = next->next;
                }
                if (visit->right) {
                    next->next = visit->right;
                    next = next->next;
                }
                cur = cur->next;
            }
            cur = dummy;
        }
    }
};
