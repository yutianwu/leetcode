class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));
        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && visit[i][j] == false) {
                    result += 1;
                    dfs(grid, visit, i, j);
                }
            }
        }
        return result;
    }

    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visit, int i, int j) {
        visit[i][j] = true;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {-1, 0, 1, 0};
        for (int m = 0; m < 4; m++) {
            int nx = i + dx[m], ny = j + dy[m];
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == '1' && !visit[nx][ny])
                dfs(grid, visit, nx, ny);
        }
    }
};
