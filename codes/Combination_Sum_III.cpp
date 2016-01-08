class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> row;
        helper(result, row, k, n, 1, 1, 0);
        return result;
    }

    void helper(vector<vector<int>> &result, vector<int> &row, int k, int n, int cur, int num, int sum) {
        if (cur > k) {
            if (sum == n) result.push_back(row);
            return;
        }
        for (int i = num; i < 10; i++) {
            if (sum + i <= n) {
                row.push_back(i);
                helper(result, row, k, n, cur + 1, i + 1, sum + i);
                row.pop_back();
            }
        }
    }
};
