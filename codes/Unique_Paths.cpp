/*
动态规划解法

用f[i][j]表示从起点(1, 1)到达（i, j）的路线条数，则状态转移方程为
f[i][j] = f[i - 1][j] + f[i][j - 1]
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>  f(n, 0);
        f[0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                f[j] = f[j] + f[j - 1];
            }
        }
        return f[n - 1];
    }
};