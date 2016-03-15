class Solution {
public:
    string convertToTitle(int n) {
        if (n <= 0) return "";

        string res = "";
        while (n != 0) {
            int remain = (n - 1) % 26;
            n = (n - 1) / 26;
            res = (char)('A' + remain) + res;
        }
        return res;
    }
};
