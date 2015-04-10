/*
    这道题和以前求最短路径的题有点相似，但是又不是求最短路径，因为要时刻保持英雄血量为正

    但是我们还是可以使用动态规划来解决，我们约定一个数组dp[rows][cols]，其中
    dp[i][j]表示进来(i, j)之前所需要的最少血量，则我们要求的结果就是dp[0][0]

    那么我们可以得到一个递归式：
    dp[i][j] = min(max(1, dp[i+1][j] - dungeon[i][j], max(1, dp[i][j+1] - dungeon[i][j])))
    
    可以这么理解，英雄进来（i, j）室后，有两条路出去，那么他出去之后所需的血量是接下来需要进入的
    密室所需要的最低血量，即dp[i+1][j]和dp[i][j+1],那么他进来这个密室之前所需要的最低血量是多少
    呢，那就很容易知道了，我们肯定选择一个出去时所需血量最少的，这样进来之前所需要的血量也是最少，
    但是，需要注意的是，英雄的血量必须时刻保持为正，所以我们取max(1, exit_HP - dungeon[i][j])

*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int rows = dungeon.size();
        int cols = rows > 0 ? dungeon[0].size() : 0;
        
        vector<int> dp(cols, INT_MAX);
        dp[cols - 1] = 1;

        for (int i = rows - 1; i >= 0; i--) {
            dp[cols - 1] = max(1, dp[cols - 1] - dungeon[i][cols - 1]);

            for (int j = cols - 2; j >= 0; j--) {
                dp[j] = max(1, min(dp[j], dp[j + 1]) - dungeon[i][j]);
            }          
        }
        return dp[0];
    }
};