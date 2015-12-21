class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i < dp.size(); i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j < dp[0].size(); j++) {
            dp[0][j] = j;
        }

        for (int i = 0; i < word1.size(); i++) {
            for (int j = 0; j < word2.size(); j++) {
                int cost = (word1[i] == word2[j] ? 0 : 1);
                dp[i + 1][j + 1] = min(dp[i][j] + cost, min(dp[i][j + 1] + 1, dp[i + 1][j] + 1));
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
