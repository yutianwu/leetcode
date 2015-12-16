/*
将问题分解成两部分，一个就是抢劫第一个，另一个就是不抢劫第一个
然后就是用上一题的解法就可以了
*/
class Solution {
public:
    int robOriginal(vector<int>& nums) {
        int dp1 = 0, dp2 = 0, res = 0;
        for(int i = 0; i < nums.size(); ++i){
            res = max(dp2 + nums[i], dp1);
            dp2 = dp1;
            dp1 = res;
        }
        return res;
    }

    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];

        vector<int> numsA(nums.begin() + 1, nums.end());
        vector<int> numsB(nums.begin(), nums.end()-1);

        return max(robOriginal(numsA), robOriginal(numsB));
    }
};
