class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> boundry;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (boundry.find(nums[i]) != boundry.end())
                continue;

            int left = (boundry.find(nums[i] - 1) == boundry.end() ? 0 : boundry[nums[i] - 1]);
            int right = (boundry.find(nums[i] + 1) == boundry.end() ? 0 : boundry[nums[i] + 1]);
            int cur = left + right + 1;
            boundry[nums[i]] = cur;
            if (left != 0)
                boundry[nums[i] - left] = cur;
            if (right != 0)
                boundry[nums[i] + right] = cur;
            res = max(res, cur);
        }
        return res;
    }
};
