class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> row;
        helper(result, row, 0, candidates, target, 0);
        return result;
    }

    void helper(vector<vector<int>> &result, vector<int> &row, int cur, vector<int> &candidates, int target, int sum) {
        if (sum == target) {
            result.push_back(row);
            return;
        }
        if (cur >= candidates.size() || sum > target) return;
        for (int i = cur; i < candidates.size(); i++) {
            row.push_back(candidates[i]);
            helper(result, row, i, candidates, target, sum + candidates[i]);
            row.pop_back();
        }
    }
};
