class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return ;
        queue<pair<int, int>> que;
        for (int i = 0; i < board[0].size(); i++) {
            if (board[0][i] == 'O') {
                board[0][i] = '+';
                que.push(make_pair(0, i));
            }
            if (board[board.size() - 1][i] == 'O') {
                board[board.size() - 1][i] = '+';
                que.push(make_pair(board.size() - 1, i));
            }
        }

        for (int j = 0; j < board.size(); j++) {
            if (board[j][0] == 'O') {
                board[j][0] = '+';
                que.push(make_pair(j, 0));
            }
            if (board[j][board[0].size() - 1] == 'O') {
                board[j][board[0].size() - 1] = '+';
                que.push(make_pair(j, board[0].size() - 1));
            }
        }

        int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
        while (!que.empty()) {
            pair<int, int> now = que.front();
            que.pop();

            for (int i = 0; i < 4; i++) {
                int nx = now.first + dx[i], ny = now.second + dy[i];
                if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && board[nx][ny] == 'O') {
                    board[nx][ny] = '+';
                    que.push(make_pair(nx, ny));
                }
            }
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '+') board[i][j] = 'O';
            }
        }
    }
};
