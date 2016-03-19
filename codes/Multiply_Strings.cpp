typedef vector<int> bigint;

bigint make_bigint(string const& repr) {
    bigint n(repr.size());
    for (int i = 0; i < repr.size(); i++)
        n[i] = repr[repr.size() - i - 1] - '0';
    return n;
}

//这里需要考虑到0011这样的情况
string to_string(bigint const& n) {
    string str;
    for (int i = n.size() - 1; i >= 0; i--) {
        if (str.size() > 0 || n[i] != 0)
            str += n[i] + '0';
    }
    return str.size() > 0 ? str : "0";
}

bigint operator*(bigint const& x, bigint const& y) {
    bigint z(x.size() + y.size());

    for (size_t i = 0; i < x.size(); i++) {
        for (size_t j = 0; j < y.size(); ++j) {
            z[i + j] += x[i] * y[j];
            z[i + j + 1] += z[i + j] / 10;
            z[i + j] %= 10;
        }
    }
    return z;
}

class Solution {
public:
    string multiply(string num1, string num2) {
        return to_string(make_bigint(num1) * make_bigint(num2));
    }
};


// 解法二

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() == 0 || num2.size() == 0)
            return "0";

        string res = "0";
        for (int i = num2.size() - 1; i >= 0; i--) {
            int n2 = num2[i] - '0', flow = 0;
            string row = "";
            for (int j = num1.size() - 1; j >= 0; j--) {
                int n1 = num1[j] - '0';
                int mul = n1 * n2 + flow;
                row = (char)(mul % 10 + '0') + row;
                flow = mul / 10;
            }
            if (flow > 0) row = (char)(flow + '0') + row;
            row = row + string(num2.size() - 1 - i, '0'); // 添0
            string newRes = "";
            flow = 0;
            int maxLen = max(res.size(), row.size());
            for (int m = 0; m < maxLen; m++) {
                int a = 0, b = 0;
                if ((int)res.size() - 1 - m >= 0) a = res[res.size() - 1 - m] - '0';
                if ((int)row.size() - 1 - m >= 0) b = row[row.size() - 1 - m] - '0';
                int sum = a + b + flow;
                newRes = (char)(sum % 10 + '0') + newRes;
                flow = sum / 10;
            }
            if (flow > 0) newRes = (char)(flow + '0') + newRes;
            res = newRes;
        }
        int i = 0;
        while (i < res.size() && res[i] == '0') i++;
        return i == res.size() ? "0" : res.substr(i);
    }

};
