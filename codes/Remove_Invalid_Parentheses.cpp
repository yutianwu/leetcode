class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        if (s.size() == 0) return {""};
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') left++;
            else if (s[i] == ')') {
                if (left > 0) left--;
                else right++;
            }
        }

        vector<string> res;
        dfs(s, "", 0, 0, 0, left, right, res);
        return res;
    }

    void dfs(string s, string newStr, int pos, int left, int right, int leftTo, int rightTo, vector<string> &res) {
        if (pos == s.size()) {
            if (left == right && leftTo == 0 && rightTo == 0) {
                bool isExist = false;
                for (int i = 0; i < res.size(); i++) {
                    if (newStr == res[i]) {
                        isExist = true;
                        break;
                    }
                }
                if (!isExist) res.push_back(newStr);
            }
            return;
        }

        if (s[pos] != '(' && s[pos] != ')')
            dfs(s, newStr + s[pos], pos + 1, left, right, leftTo, rightTo, res);

        if (s[pos] == '(') {
            dfs(s, newStr + '(', pos + 1, left + 1, right, leftTo, rightTo, res);
            if (left >= right && leftTo > 0)
                dfs(s, newStr, pos + 1, left, right, leftTo - 1, rightTo, res);
        }
        if (s[pos] == ')') {
            if (left > right)
                dfs(s, newStr + ')', pos + 1, left, right + 1, leftTo, rightTo, res);
            if (rightTo > 0)
                dfs(s, newStr, pos + 1, left, right, leftTo, rightTo - 1, res);
        }
    }
};
