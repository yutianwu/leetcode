
/*
动态规划解法：
设状态为f(i,j),表示区间[i, j]是否为回文串，则状态转移方程为：

            true                                , i = j
f(i, j) =   s[i] == s[j]                        , j = i + 1
            s[i] == s[j] && f(i + 1, j - 1)     , j > i + 1

*/
class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        bool f[n][n];
        fill_n(&f[0][0], n * n, false);

        size_t max_len = 1, start = 0;

        for (size_t i = 0; i < s.size(); i++) {
            f[i][i] = true;
            for (size_t j = 0; j < i; j++) {
                f[j][i] = (s[j] == s[i] && (i - j < 2 || f[j + 1][i - 1]));
                if (f[j][i] && max_len < (i - j + 1)) {
                    max_len = i - j + 1;
                    start = j;
                }
            }
        }
        return s.substr(start, max_len);
    }
};


/*
Manacher’s Algorithm 线性时间解法

reference:  http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
*/
class Solution {
public:
    // Transform S into T.
    // For example, S = "abba", T = "^#a#b#b#a#$".
    // ^ and $ signs are sentinels appended to each end to avoid bounds checking
    string preProcess(string s) {
      int n = s.length();
      if (n == 0) return "^$";
      string ret = "^";
      for (int i = 0; i < n; i++)
        ret += "#" + s.substr(i, 1);

      ret += "#$";
      return ret;
    }

    string longestPalindrome(string s) {
      string T = preProcess(s);
      int n = T.length();
      int *P = new int[n];
      int C = 0, R = 0;
      for (int i = 1; i < n-1; i++) {
        int i_mirror = 2*C-i; // equals to i' = C - (i-C)

        P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;

        // Attempt to expand palindrome centered at i
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
          P[i]++;

        // If palindrome centered at i expand past R,
        // adjust center based on expanded palindrome.
        if (i + P[i] > R) {
          C = i;
          R = i + P[i];
        }
      }

      // Find the maximum element in P.
      int maxLen = 0;
      int centerIndex = 0;
      for (int i = 1; i < n-1; i++) {
        if (P[i] > maxLen) {
          maxLen = P[i];
          centerIndex = i;
        }
      }
      delete[] P;

      return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
    }
};
