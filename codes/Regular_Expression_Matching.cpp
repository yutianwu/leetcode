// DP
/*
This problem has a typical solution using Dynamic Programming. We define the state P[i][j] to be true if s[0..i) matches p[0..j) and false otherwise. Then the state equations are:

P[i][j] = P[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
P[i][j] = P[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 times;
P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 times.

*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        bool dp[m + 1][n + 1];
        fill_n(&dp[0][0], (m + 1) * (n + 1), false);

        dp[0][0] = true;
        for (int i = 0; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                else
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
        return dp[m][n];
    }
};

//DFS
class Solution {
public:
    bool isMatch(string s, string p) {
        return dfs(s, 0, p, 0);
    }

    bool dfs(string s, int ps, string p, int pp) {
        if (s.size() == ps) {
            if (pp  == p.size()) return true;
            if (pp + 1 >= p.size()) return false;
            else {
                if (p[pp + 1] != '*') return false;
                return dfs(s, ps, p, pp + 2);
            }
        }

        if (pp == p.size()) return false;
        char cur = p[pp], next = pp + 1 >= p.size() ? '0' : p[pp + 1];
        if (cur != s[ps] && cur != '.') {
            if (next == '*')
                return dfs(s, ps, p, pp + 2);
            return false;
        } else {
            if (next != '*')
                return dfs(s, ps + 1, p, pp + 1);

            if (dfs(s, ps, p, pp + 2)) return true;
            while (ps < s.size() && (s[ps] == cur || cur == '.')) {
                if (dfs(s, ps + 1, p, pp + 2)) return true;
                ps = ps + 1;
            }
            return false;
        }
    }
};
