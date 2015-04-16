/*
利用上一题的解法，将数组[0..n]分成两段来看
maxProfit[0..n] = max(maxProfit[0..i], maxProfit[i..n])
而求maxProfit[0..i]与maxProfit[i..n]可以利用上一题的解法，so easy
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        
        vector<int> toRight(prices.size(), 0);
        vector<int> toLeft(prices.size(), 0);
        
        calculate(prices, toRight, toLeft);
        
        int res = 0;
        for (int i = 0; i < prices.size(); i++) {
            res = max(res, toRight[i] + toLeft[i]);
        }
        return res;
    }
private:
    void calculate(vector<int> &prices, vector<int> &toRight, vector<int> &toLeft) {
        int minPrice = prices[0];
        int maxPrice = prices[prices.size() - 1];
        
        for (int i = 1; i < prices.size(); i++) {
            toRight[i] = max(toRight[i - 1], prices[i] - minPrice);
            minPrice = min(prices[i], minPrice);
        }
        
        for (int i = prices.size() - 2; i >= 0; i--) {
            toLeft[i] = max(toLeft[i + 1], maxPrice - prices[i]);
            maxPrice = max(prices[i], maxPrice);
        }
    }
};