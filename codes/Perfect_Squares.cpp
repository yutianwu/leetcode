class Solution {
public:
    int numSquares(int n) {
        if (n == 0) return 0;
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int range = sqrt(i);
            for (int j = 1; j <= range; j++) {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }
        
        return dp[n];
    }
};