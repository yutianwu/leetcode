/*
    dp[i+1] = max(dp[i], prices[i] - minprice)
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) return 0;
        
        vector<int> dp(prices.size());
        int minprice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i] = max(dp[i - 1], prices[i] - minprice);
            minprice = min(minprice, prices[i]);
        }
        
        return dp[prices.size() - 1];
    }
};