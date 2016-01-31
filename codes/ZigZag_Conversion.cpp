class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> rows(numRows, "");
        int pos = 0, direct = 1;
        for (int i = 0; i < s.size(); i++) {
            rows[pos] += s[i];
            if (pos == numRows - 1) direct = -1;
            if (pos == 0) direct = 1;
            pos = pos + direct;
        }
        string result;
        for (int i = 0; i < numRows; i++)
            result += rows[i];

        return result;
    }
};
