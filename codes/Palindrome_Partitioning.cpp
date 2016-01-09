class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> row;
        helper(result, row, s, 0);
        return result;
    }

    void helper(vector<vector<string>> &result, vector<string> &row, string s, int pos) {
        if (pos >= s.size()) {
            result.push_back(row);
            return;
        }

        for (int i = pos; i < s.size(); i++) {
            if (isPalindrome(s, pos, i)) {
                row.push_back(s.substr(pos, i - pos + 1));
                helper(result, row, s, i + 1);
                row.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int begin, int end) {
        while (begin <= end) {
            if (s[begin] != s[end]) return false;
            begin++;
            end--;
        }
        return true;
    }
};
