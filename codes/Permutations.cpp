class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() == 0) return result;
        permute(result, nums, 0);
        return result;
    }

    void permute(vector<vector<int>> &result, vector<int> &nums, int cur) {
        if (cur == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = cur; i < nums.size(); i++) {
            swap(nums[i], nums[cur]);
            permute(result, nums, cur + 1);
            swap(nums[i], nums[cur]);
        }
    }
};
