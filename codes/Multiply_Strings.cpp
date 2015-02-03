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