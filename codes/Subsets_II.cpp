class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
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

        int num = 0;
        for (int i = cur; i < nums.size(); i++) {
            if (nums[i] != nums[cur]) break;
            num ++;
        }
        helper(result, row, nums, cur + num);
        for (int i = 0; i < num; i++) {
            row.push_back(nums[cur]);
            helper(result, row, nums, cur + num);
        }
        for (int i = 0; i < num; i++) {
            row.pop_back();
        }
    }
};
