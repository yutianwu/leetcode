class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int dp = nums[0];
        int global = dp;
        for (int i = 1; i < nums.size(); i++) {
            dp = dp > 0 ? nums[i] + dp : nums[i];
            global = max(global, dp);
        }
        return global;
    }
};
