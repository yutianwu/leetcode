struct SegTreeNode {
    int begin, end, sum;
    SegTreeNode *left, *right;
    SegTreeNode(int begin, int end): begin(begin), end(end) {}
};

class NumArray {
private:
    SegTreeNode *root;
public:
    NumArray(vector<int> &nums) {
        root = buildTree(nums, 0, nums.size() - 1);
    }

    SegTreeNode *buildTree(vector<int> &nums, int begin, int end) {
        if (begin > end) return NULL;

        SegTreeNode *root = new SegTreeNode(begin, end);
        if (begin == end) {
            root->sum = nums[begin];
            return root;
        }

        int mid = begin + (end - begin) / 2;
        root->left = buildTree(nums, begin, mid);
        root->right = buildTree(nums, mid + 1, end);

        int sum = 0;
        if (root->left) sum += root->left->sum;
        if (root->right) sum += root->right->sum;
        root->sum = sum;
        return root;
    }

    void update(int i, int val) {
        update(i, val, root);
    }

    void update(int i, int val, SegTreeNode *cur) {
        if (cur == NULL) return;

        if (cur->begin == cur->end && cur->begin == i) {
            cur->sum = val;
            return;
        }

        int mid = cur->begin + (cur->end - cur->begin) / 2;
        if (mid >= i)
            update(i, val, cur->left);
        if (mid < i)
            update(i, val, cur->right);

        cur->sum = (cur->left ? cur->left->sum : 0) + (cur->right ? cur->right->sum : 0);
    }

    int sumRange(int i, int j) {
        return sumRange(i, j, root);
    }
    int sumRange(int i, int j, SegTreeNode *cur) {
        if (cur == NULL) return 0;

        if (i <= cur->begin && j >= cur->end) {
            return cur->sum;
        } else if (i > cur->end || j < cur->begin) {
            return 0;
        } else {
            int left = sumRange(i, j, cur->left);
            int right = sumRange(i, j, cur->right);
            return left + right;
        }
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
