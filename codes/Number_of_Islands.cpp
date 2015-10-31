class Solution {
private:
    int cols = 0;
    int rows = 0;
public:
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = 0;
        if (rows > 0) 
            cols = grid[0].size();
        
        int isLands = 0;
        vector<bool> row(cols, false);
        vector<vector<bool> > visit(rows, row);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (visit[i][j] == false && grid[i][j] == '1') {
                    isLands++;
                    dfs(grid, visit, i, j);
                }
            }
        }
        return isLands;
    }
    
    void dfs(vector<vector<char>>& grid, vector<vector<bool> > &visit, int row, int col) {
        if (grid[row][col] != '1' || visit[row][col] == true) return;
        
        visit[row][col] = true;
        if (col - 1 >= 0) 
            dfs(grid, visit, row, col - 1);
        if (col + 1 < cols) 
            dfs(grid, visit, row, col + 1);
        if (row - 1 >= 0)
            dfs(grid, visit, row - 1, col);
        if (row + 1 < rows)
            dfs(grid, visit, row + 1, col);
    }
};