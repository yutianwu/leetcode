/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
	stack<TreeNode * > levels;
	
public:
    BSTIterator(TreeNode *root) {
		while (root != NULL) {
			levels.push(root);
			root = root->left;
		}
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
		return !levels.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *butt = levels.top();
		levels.pop();

		int res = butt->val;
		TreeNode *pointer = butt->right;
		
		while (pointer != NULL) {
			levels.push(pointer);
			pointer = pointer->left;
		}
		return res;
    }
};


/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */