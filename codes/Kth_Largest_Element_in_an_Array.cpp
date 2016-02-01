class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int> > que;
        for (int i = 0; i < nums.size(); i++) {
            que.push(nums[i]);
        }

        for (int i = 1; i < k; i++) {
            que.pop();
        }
        return que.top();
    }
};

// 解法二
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int j = partition(nums, lo, hi);
            if (j < k)
                lo = j + 1;
            else if (j > k)
                hi = j - 1;
            else
                break;
        }
        return nums[k];
    }

    int partition(vector<int> &nums, int lo, int hi) {
        int random = lo + rand() % (hi - lo + 1);
        swap(nums[random], nums[hi]);

        int tmp = nums[hi];
        int pre = lo - 1;
        for (int i = lo; i < hi; i++) {
            if (nums[i] <= tmp) swap(nums[i], nums[++pre]);
        }
        swap(nums[++pre], nums[hi]);
        return pre;
    }
};
