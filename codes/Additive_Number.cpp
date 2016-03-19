class Solution {
public:
    bool isAdditiveNumber(string num) {
        if (num.size() < 3) return false;
        return helper(num, 0, "", "", false);
    }

    bool helper(string num, int pos, string num1, string num2, bool isSum) {
        if (pos >= num.size()) return isSum;
        for (int i = pos; i < num.size(); i++) {
            string sum = num.substr(pos, i - pos + 1);
            if (num1 == "") {
                if (helper(num, i + 1, sum, num2, false)) return true;
            } else if (num2 == "") {
                if (helper(num, i + 1, num1, sum, false)) return true;
            } else if (sum == addString(num1, num2)) {
                if (helper(num, i + 1, num2, sum, true)) return true;
            }
            if (num[pos] == '0') return false;
        }
        return false;
    }

    string addString(string num1, string num2) {
        int flow = 0;
        int size = max(num1.size(), num2.size());
        string res = "";
        for (int i = 0; i < size; i++) {
            int a = 0, b = 0;
            if ((int)num1.size() - 1 - i >= 0) a = num1[num1.size() - 1 - i] - '0';
            if ((int)num2.size() - 1 - i >= 0) b = num2[num2.size() - 1 - i] - '0';
            int sum = a + b + flow;
            res = (char)(sum % 10 + '0') + res;
            flow = sum / 10;
        }

        if (flow == 1) res = '1' + res;
        return res;
     }
};
