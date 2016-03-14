class Solution {
public:
    int totalNQueens(int n) {
        if (n <= 0) return 0;
        vector<int> queens;
        int result = 0;
        dfs(queens, result, n);
        return result;
    }

    void dfs(vector<int> &queens, int &result, int n) {
        if (queens.size() == n) {
            result += 1;
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
