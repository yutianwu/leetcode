class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() <= 3)
            return accumulate(nums.begin(), nums.end(), 0);

        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(target - ans) > abs(target - sum)) {
                    ans = sum;
                    if (target == sum) return ans;
                }
                sum > target ? k-- : j++;
            }
        }
        return ans;
    }
};
