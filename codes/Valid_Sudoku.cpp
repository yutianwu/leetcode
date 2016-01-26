class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size() != 9 || board[0].size() != 9) return false;

        for (int i = 0; i < 9; i++) {
            unordered_set<char> row, col;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' && (board[i][j] < '1' || board[i][j] > '9')) return false;
                if (board[j][i] != '.' && (board[j][i] < '1' || board[j][i] > '9')) return false;

                if (board[i][j] != '.' && row.find(board[i][j]) != row.end() ) return false;
                if (board[j][i] != '.' && col.find(board[j][i]) != col.end() ) return false;
                row.insert(board[i][j]);
                col.insert(board[j][i]);
            }
        }

        for (int i = 0; i < 9; i++) {
            int ox = (i / 3) * 3, oy = (i % 3) * 3;
            unordered_set<char> dict;
            for (int m = 0; m < 3; m++) {
                for (int n = 0; n < 3; n++) {
                    if (board[ox + m][oy + n] != '.'
                            && (board[ox + m][oy + n] < '1' || board[ox + m][oy + n] > '9')) return false;

                    if (board[ox + m][oy + n] != '.' && dict.find(board[ox + m][oy + n]) != dict.end()) return false;
                    dict.insert(board[ox + m][oy + n]);
                }
            }
        }
        return true;
    }
};
