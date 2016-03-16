class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }

    bool solve(vector<vector<char>> &board, int x, int y) {
        if (x >= 9) return true;
        int nx = x + (y + 1) / 9, ny = (y + 1) % 9;
        if (board[x][y] != '.')
            return solve(board, nx, ny);

        for (int i = 1; i <= 9; i++) {
            if (check(board, x, y, i)) {
                board[x][y] = (char)(i + '0');
                bool solved = solve(board, nx, ny);
                if (solved) return true;
                board[x][y] = '.';
            }
        }
        return false;
     }

     bool check(vector<vector<char>> &board, int x, int y, int v) {
        for (int i = 0; i < 9; i++)
            if (board[x][i] == (char)(v + '0')) return false;
        for (int i = 0; i < 9; i++)
            if (board[i][y] == (char)(v + '0')) return false;

        int row = (x / 3) * 3;
        int col = (y / 3) * 3;
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (board[i][j] == (char)(v + '0')) return false;
            }
        }
        return true;
     }
};
