class Solution {
public:
    /**
     * 0 for 0
     * 1 for 1
     * 2 for 0 to 1
     * 3 for 1 to 0
     */
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = 0;
        if (rows > 0)
            cols = board[0].size();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int count = getLiveCount(i, j, board);

                if (count < 2) 
                    board[i][j] = board[i][j] == 0 ? 0 : 3;
                
                if (count > 3)
                    board[i][j] = board[i][j] == 1 ? 3 : 0;
                
                if (count == 3)
                    board[i][j] = board[i][j] == 0 ? 2 : 1;
            }
        }
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] > 1)
                    board[i][j] = (board[i][j] + 1) % 2;
            }
        }
    }
    
    int getLiveCount(int row, int col, vector<vector<int>>& board) {
        int count = 0;
        int rows = board.size();
        int cols = 0;
        if (rows > 0) cols = board[0].size();

        for (int i = -1; i <= 1; i++) {
            for (int j = - 1; j <= 1; j++) {
                if (row + i >= 0 && row + i < rows && col + j >= 0 && col + j < cols)
                    count += board[row + i][col + j] % 2;
            }
        }
        return count - board[row][col];
    }
};