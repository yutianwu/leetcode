class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;

        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int maxNum = 0;
        for (int i = 0; i < rows; i++) {
            if ('1' == matrix[i][0]) {
                maxNum = 1;
                dp[i][0] = 1;
            }
        }
        for (int j = 0; j < cols; j++) {
            if ('1' == matrix[0][j]) {
                maxNum = 1;
                dp[0][j] = 1;
            }
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                    maxNum = max(maxNum, dp[i][j]);
                }
            }
        }
        return maxNum * maxNum;
    }
};
