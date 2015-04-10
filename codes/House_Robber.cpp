/*
	分类：动态规划

	这个题很容易想到，我们设一个数组dp[nums]
	其中dp[i]为有i户人家能偷到的最大值
	那么dp[i] = max(num[i] + dp[i-2], dp[i-1])
	可以这么理解，假如有i户人家，那么小偷有两个选择，偷第i户人家，那么这时最优的解
	应该为num[i] + dp[i-2],如果不偷第i户人家，那么最优解为dp[i-1]
*/

class Solution {
public:
    int rob(vector<int> &num) {
        int nums = num.size();
        if (nums == 0) return 0;
        
        vector<int> dp(nums + 2, 0);
        for (int i = 2; i < nums + 2; i++) {
            dp[i] = max(num[i - 2] + dp[i - 2], dp[i - 1]);
        }
        return dp[nums + 1];
    }
};