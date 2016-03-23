class Solution {
public:
    vector<int> maxArray(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> ans(k, 0);
        for (int i = 0, j = 0; i < n; ++i) {
            while (n - i + j > k && j > 0 && ans[j - 1] < nums[i]) j--;
            if (j < k) ans[j++] = nums[i];
        }
        return ans;
    }

    bool compare(vector<int> &nums1, int i, vector<int> &nums2, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            i++;
            j++;
        }
        return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
    }

    vector<int> mergeTwoArrays(vector<int> &num1, vector<int> &num2) {
        vector<int> result(num1.size() + num2.size(), 0);
        for (int i = 0, j = 0, r = 0; r < num1.size() + num2.size(); r++)
            result[r] = compare(num1, i, num2, j) ? num1[i++] : num2[j++];

        return result;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> res(k, 0);
        for (int i = max(0, k - m); i <= k && i <= n; i++) {
            vector<int> first = maxArray(nums1, i);
            vector<int> second = maxArray(nums2, k - i);
            vector<int> candidate = mergeTwoArrays(first, second);
            if (compare(candidate, 0, res, 0))
                res = candidate;
        }
        return res;
    }
};
