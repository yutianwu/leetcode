class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word == "") return true;
        if (board.size() == 0 || board[0].size() == 0) return false;

        int rows = board.size(), cols = board[0].size();
        vector<vector<bool>> visit(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0] && !visit[i][j]) {
                    bool res = dfs(board, visit, word, 0, i, j);
                    if (res) return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>> &visit, string word, int pos, int row, int col) {
        if (board[row][col] != word[pos] || visit[row][col]) return false;
        if (pos == word.size() - 1) return true;

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        visit[row][col] = true;
        bool res = false;
        for (int i = 0; i < 4; i++) {
            int x = row + dx[i], y = col + dy[i];
            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && !visit[x][y] && board[x][y] == word[pos + 1])
                res = dfs(board, visit, word, pos + 1, x, y);

            if (res) break;
        }
        visit[row][col] = false;
        return res;
    }
};
