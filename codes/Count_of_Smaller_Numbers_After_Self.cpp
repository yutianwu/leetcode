struct SegTreeNode {
    int begin, end, count;
    SegTreeNode *left, *right;
    SegTreeNode(int begin, int end): begin(begin), end(end), count(0) {}
};


class Solution {
private:
    SegTreeNode *root;

public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.size() == 0) return {};
        int minnum = nums[0],  maxnum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < minnum) minnum = nums[i];
            if (nums[i] > maxnum) maxnum = nums[i];
        }

        root = buildTree(minnum, maxnum);

        vector<int> result;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int count = query(root, minnum, nums[i] - 1);
            result.push_back(count);
            addNode(root, nums[i]);
        }
        return vector<int>(result.rbegin(), result.rend());
    }

    int query(SegTreeNode *root, int start, int end) {
        if (root == NULL) return 0;
        if (start <= root->begin && end >= root->end) return root->count;
        else if (start > root->end || end < root->begin) return 0;
        else {
            return query(root->left, start, end) + query(root->right, start, end);
        }
    }

    SegTreeNode *buildTree(int start, int end) {
        if (start > end) return NULL;
        if (start == end)
            return new SegTreeNode(start, end);

        SegTreeNode *root = new SegTreeNode(start, end);
        int mid = start + (end - start) / 2;
        root->left = buildTree(start, mid);
        root->right = buildTree(mid + 1, end);
        return root;
    }

    void addNode(SegTreeNode *root, int num) {
        if (root == NULL) return;
        if (root->begin == root->end) {
            if (root->begin == num) root->count += 1;
            return;
        }
        int mid = root->begin + (root->end - root->begin) / 2;
        if (num <= mid) addNode(root->left, num);
        else addNode(root->right, num);

        root->count = root->left->count + root->right->count;
    }
};
