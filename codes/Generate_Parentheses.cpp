class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0) return result;
        string item;
        helper(result, item, n, n);
        return result;
    }

    void helper(vector<string> &result, string item, int left, int right) {
        if (left == 0 && right == 0) {
            result.push_back(item);
            return;
        }
        if (left > 0) helper(result, item + "(", left - 1, right);
        if (right > left) helper(result, item + ")", left, right - 1);
    }
};
