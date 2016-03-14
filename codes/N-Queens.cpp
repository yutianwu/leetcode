class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        if (n <= 0) return {};
        vector<int> queens;
        vector<vector<string>> result;
        dfs(queens, result, n);
        return result;
    }

    void dfs(vector<int> &queens, vector<vector<string>> &result, int n) {
        if (queens.size() == n) {
            vector<string> solution;
            for (int i = 0; i < n; i++) {
                int col = queens[i];
                string tmp = "";
                for (int j = 0; j < n; j++) {
                    if (col == j)
                        tmp += "Q";
                    else
                        tmp += ".";
                }
                solution.push_back(tmp);
            }
            result.push_back(solution);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (checkValid(queens, i)) {
                queens.push_back(i);
                dfs(queens, result, n);
                queens.pop_back();
            }
        }
    }

    bool checkValid(vector<int> &queens, int pos) {
        int row = queens.size();
        for (size_t i = 0; i < queens.size(); i++) {
            if (queens[i] == pos) return false;
            if (abs(row - i) == abs(pos - queens[i])) return false;
        }
        return true;
    }
};
