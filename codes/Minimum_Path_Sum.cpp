class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        vector<int> dp(grid[0].size(), INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < grid.size(); i++) {
            dp[0] = grid[i][0] + dp[0];
            for (int j = 1; j < grid[i].size(); j++)
                dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
        }
        return dp[grid[0].size() - 1];
    }
};
