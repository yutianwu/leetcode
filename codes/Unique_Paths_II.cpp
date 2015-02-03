/*
和上一题的区别就是加了障碍
这里需要多考虑点的就是第一列的情况和碰到障碍的情况
在上一题是不需要考虑第一列的情况的，因为第一列的走法都是1，但是这里需要考虑第一列有障碍的情况；
当碰到障碍时，就应该把该处的走法置为0
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        if (obstacleGrid[0][0] || obstacleGrid[rows - 1][cols - 1]) return 0;
        
        vector<int> f(cols, 0);
        f[0] = obstacleGrid[0][0] ? 0 : 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                f[j] = obstacleGrid[i][j] ? 0 : (j == 0 ? 0 : f[j - 1]) + f[j]; 
            }
        }
        return f[cols - 1];
    }
};