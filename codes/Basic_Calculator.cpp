class Solution {
public:
    int calculate(string s) {
        if (s.size() == 0) return 0;
        stack<int> st;
        int res = 0, sign = 1;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                int num = c - '0';
                while (i + 1 < s.size() && s[i + 1] >= '0' && s[i + 1] <= '9') {
                    num = num * 10 + (s[i + 1] - '0');
                    i++;
                }
                res += sign * num;
            } else if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if (c == ')') {
                int preSign = st.top();
                st.pop();
                int preRes = st.top();
                st.pop();
                res = res * preSign + preRes;
                sign = 1;
            }
        }
        return res;
    }
};
