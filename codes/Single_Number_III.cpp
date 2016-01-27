
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for (int i = 0; i < nums.size(); i++)
            diff ^= nums[i];

        diff &= -diff;

        vector<int> result(2, 0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & diff)
                result[0] ^= nums[i];
            else
                result[1] ^= nums[i];
        }
        return result;
    }
};
