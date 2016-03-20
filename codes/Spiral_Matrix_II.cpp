class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n <= 0) return {};
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int cur = 1;
        for (int i = 0; i < (n + 1) / 2; i++) {
            for (int j = i; j < n - i; j++)
                matrix[i][j] = cur++;
            for (int j = i + 1; j < n - i - 1; j++)
                matrix[j][n - i - 1] = cur++;
            for (int j = n - i - 1; j >= i && (i + 1) <= (n - 1 - i); j--)
                matrix[n - i - 1][j] = cur++;
            for (int j = n - i - 2; j >= i + 1; j--)
                matrix[j][i] = cur++;
        }
        return matrix;
    }
};
