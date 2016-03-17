class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), INT_MIN));
        vector<vector<bool>> visit(matrix.size(), vector<bool>(matrix[0].size(), false));
        int result = INT_MIN;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (dp[i][j] == INT_MIN) {
                    int longest = dfs(matrix, i, j, 0, visit, dp);
                    result = max(longest, result);
                } else {
                    result = max(result, dp[i][j]);
                }
            }
        }
        return result;
    }

    int dfs(vector<vector<int>> &matrix, int x, int y, int len, vector<vector<bool>> &visit, vector<vector<int>> &dp) {
        int longest = len + 1;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        visit[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < matrix.size() && ny >=0 && ny < matrix[0].size()
                    && !visit[nx][ny] && matrix[nx][ny] > matrix[x][y]) {

                if (dp[nx][ny] != INT_MIN) {
                    longest = max(longest, len + 1 + dp[nx][ny]);
                } else {
                    longest = max(longest, dfs(matrix, nx, ny, len + 1, visit, dp));
                }
            }
        }

        visit[x][y] = false;
        dp[x][y] = longest - len;
        return longest;
    }
};
