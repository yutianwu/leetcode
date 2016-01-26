class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows == 0) return result;
        vector<int> firstRow(1, 1);
        result.push_back(firstRow);
        for (int i = 2; i <= numRows; i++) {
            vector<int> lastRow = result[i - 2];
            vector<int> row(i, 1);

            for (int j = 1; j < i - 1; j++)
                row[j] = lastRow[j - 1] + lastRow[j];

            result.push_back(row);
        }
        return result;
    }
};
