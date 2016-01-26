class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> dict;
        for (int i = 0; i < nums.size(); i++) {
            if (dict.find(nums[i]) != dict.end())
                dict[nums[i]] += 1;
            else
                dict[nums[i]] = 1;

            if (dict[nums[i]] > nums.size() / 2)
                return nums[i];
        }
        return 0;
    }
};
