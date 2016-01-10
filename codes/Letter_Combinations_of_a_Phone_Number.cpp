class Solution {
public:

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() == 0) return result;
        string item;
        helper(result, item, digits, 0);
        return result;
    }

    void helper(vector<string> &result, string item, string &digits, int pos) {
        if (pos >= digits.size()) {
            result.push_back(item);
            return;
        }
        string dict[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int digit = digits[pos] - '0';
        if (digit > 1 && digit < 10) {
            for (int i = 0; i < dict[digit].size(); i++)
                helper(result, item + dict[digit][i], digits, pos + 1);
        } else {
            helper(result, item, digits, pos + 1);
        }
    }
};
