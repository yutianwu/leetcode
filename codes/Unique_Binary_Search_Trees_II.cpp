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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();

        return generateTrees(1, n);
    }

    vector<TreeNode*> generateTrees(int s, int e) {
        vector<TreeNode*> result;
        if (s > e) {
            result.push_back(NULL);
            return result;
        }
        for (int i = s; i <= e; i++) {
            vector<TreeNode*> left = generateTrees(s, i - 1);
            vector<TreeNode*> right = generateTrees(i + 1, e);

            for (int m = 0; m < left.size(); m++) {
                for (int n = 0; n < right.size(); n++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left[m];
                    root->right = right[n];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};
