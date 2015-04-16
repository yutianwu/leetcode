/*
使用两个数组：global[i][j], local[i][j]
global[i][j]表示到第i天，进行j次交易最大的利润
local[i][j]表示到第i天，而且第i天交易，进行j次交易最大的利润

得到递推公式：
local[i][j] = max(global[i-1][j-1] + max(diff, 0), local[i - 1][j] + diff)

global[i][j] = max(local[i][j], global[i-1][j])


但是这有一个地方需要注意，就是当交易次数大于天数时，这样做就不好了，可以直接转换成第二题，即在
i天里不管进行多少次交易，求最大的利润
*/

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int len = prices.size();
        if (len <= 1 || k <= 0) return 0;
        if (k >= len) return solveMaxProfit(prices);
        
        vector<vector<int> > global(len, vector<int>(k + 1, 0));
        vector<vector<int> > local(len, vector<int>(k + 1, 0));
        
        for (int i = 1; i < len; i++) {
            int diff = prices[i] - prices[i - 1];
            for (int j = 1; j <= k; j++) {
                local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff);
                global[i][j] = max(local[i][j], global[i - 1][j]);
            }
        }
        
        return global[len - 1][k];
    }
private:
    int solveMaxProfit(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] - prices[i - 1] > 0) {
                res += prices[i] - prices[i - 1];
            }
        }
        return res;
    }
};