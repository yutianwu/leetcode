class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        for (int i = 0; i < nums.size(); ) {
            int cur = i;
            while (cur + 1 < nums.size() && nums[cur] + 1 == nums[cur + 1]) cur++;
            if (i == cur) {
                result.push_back(to_string(nums[i]));
            } else {
                string tmp = to_string(nums[i]) + "->" + to_string(nums[cur]);
                result.push_back(tmp);
            }
            i = cur + 1;
        }
        return result;
    }
};
