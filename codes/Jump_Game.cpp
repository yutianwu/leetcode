class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ability = 0;
        for (int i = 0; i < nums.size() - 1 && ability >= i; i++)
            ability = max(ability, i + nums[i]);
        return ability >= nums.size() - 1 ? true : false;
    }
};
