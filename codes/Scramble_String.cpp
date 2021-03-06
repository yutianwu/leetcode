/*
    dp[n][i][j]，表示长度为n，起点为s1[i], s2[j]的两个字符串是否为scramble

    那么dp[n][i][j] = (dp[k][i][j] && dp[n-k][i+k][j+k]) ||
                    (dp[k][i][j+n-k] && dp[n-k][i+k][j])

    意思是如果dp[n][i][j]为true的话，那么要么s1的左边与s2的左边，s1的右边与s2的右边互为scramble，
    要么s1的左边与s2的右边，s1的右边与s2的左边互为scramble

*/

class Solution {
public:
    bool isScramble(string s1, string s2) {
        const int N = s1.size();
        if (N != s2.size()) return false;

        bool dp[N + 1][N][N];
        fill_n(&dp[0][0][0], (N + 1) * N * N, false);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dp[1][i][j] = (s1[i] == s2[j]);

        for (int n = 1; n <= N; ++n) {
            for (int i = 0; i + n <= N; ++i) {
                for (int j = 0; j + n <= N; ++j) {
                    for (int k = 1; k < n; ++k) {
                        if ((dp[k][i][j] && dp[n - k][i + k][j + k]) ||
                                (dp[k][i][j + n - k] && dp[n - k][i + k][j])) {
                                dp[n][i][j] = true;
                                break;
                        }
                    }
                }
            }
        }
        return dp[N][0][0];
    }
};

//解法二
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1==s2)
            return true;

        int len = s1.length();
        int count[26] = {0};
        for(int i=0; i<len; i++)
        {
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }

        for(int i=0; i<26; i++)
        {
            if(count[i]!=0)
                return false;
        }

        for(int i=1; i <= len-1; i++)
        {
            if( isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if( isScramble(s1.substr(0,i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0,len-i)))
                return true;
        }
        return false;
    }
};
