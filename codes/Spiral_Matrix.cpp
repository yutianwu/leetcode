class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.size() == 0 || matrix[0].size() == 0) return result;
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = -1;
        while (true) {
            for (int i = 0; i < n; i++)
                result.push_back(matrix[row][++col]);
            if (--m == 0) break;
            for (int i = 0; i < m; i++)
                result.push_back(matrix[++row][col]);
            if (--n == 0) break;
            for (int i = 0; i < n; i++)
                result.push_back(matrix[row][--col]);
            if (--m == 0) break;
            for (int i = 0; i < m; i++)
                result.push_back(matrix[--row][col]);
            if (--n == 0) break;
        }
        return result;
    }
};
