/*
想法和上一题一样，但是中间加了一个数组inter，inter[i][j]表示（i,j]可以组成一个单词，
这样最后就可以使用DFS来找出所有路径
*/
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        
        vector<vector<bool> > inter(s.size() + 1, vector<bool>(s.size(), false));
        
        for (int i = 1; i <= s.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = true;
                    inter[i][j] = true;
                }
            }
        }
        
        vector<string> result;
        vector<string> path;
        genPath(s, inter, path, result, s.size());
        return result;
    }

private:
    void genPath(string &s, vector<vector<bool> > &inter, vector<string> &path, vector<string> &res, int cur) {
        if (cur == 0) {
            string tmp = "";
            for (int i = path.size() - 1; i >= 0; i--) {
                tmp += path[i] + " ";
            }
            res.push_back(tmp.substr(0, tmp.size() - 1));
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (inter[cur][i]) {
                path.push_back(s.substr(i, cur - i));
                genPath(s, inter, path, res, i);
                path.pop_back();
            }
        }
    }
};