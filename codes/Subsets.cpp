class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> row;
        helper(result, row, nums, 0);
        return result;
    }

    void helper(vector<vector<int>> &result, vector<int> &row, vector<int> &nums, int cur) {
        if (cur >= nums.size()) {
            result.push_back(row);
            return;
        }
        helper(result, row, nums, cur + 1);
        row.push_back(nums[cur]);
        helper(result, row, nums, cur + 1);
        row.pop_back();
    }
};
