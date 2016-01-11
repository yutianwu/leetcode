class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        helper(result, nums, 0);
        return result;
    }
    void helper(vector<vector<int>> &result, vector<int> nums, int pos) {
        if (pos == nums.size() - 1) {
            result.push_back(nums);
            return;
        }

        for (int i = pos; i < nums.size(); i++) {
            if (i == pos || nums[pos] != nums[i]) {
                swap(nums[pos], nums[i]);
                helper(result, nums, pos + 1);
            }
        }
    }
};
