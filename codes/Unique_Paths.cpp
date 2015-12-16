/*
滚动数组，可以将O(m*n)的空间复杂度降至O(n)
但是也不是每个题都可以这么使用，但是得知道有这么个方法可以降低空间复杂度

用f[i][j]表示从起点(1, 1)到达（i, j）的路线条数，则状态转移方程为
f[i][j] = f[i - 1][j] + f[i][j - 1]
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};
