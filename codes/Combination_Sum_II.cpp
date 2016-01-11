class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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

        int num = 0;
        for (int i = cur; i < candidates.size(); i++) {
            if (candidates[i] != candidates[cur]) break;
            num++;
        }

        helper(result, row, cur + num, candidates, target, sum);
        for (int i = 1; i <= num; i++) {
            row.push_back(candidates[cur]);
            helper(result, row, cur + num, candidates, target, sum + i * candidates[cur]);
        }
        for (int i = 1; i <= num; i++) {
            row.pop_back();
        }
    }
};
