class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> row;
        helper(result, row, k, n, 1, 1);
        return result;
    }

    void helper(vector<vector<int>> &result, vector<int> &row, int k, int n, int cur, int num) {
        if (cur > k) {
            result.push_back(row);
            return;
        }

        for (int i = num; i <= n; i++) {
            row.push_back(i);
            helper(result, row, k, n, cur + 1, i + 1);
            row.pop_back();
        }
    }
};
