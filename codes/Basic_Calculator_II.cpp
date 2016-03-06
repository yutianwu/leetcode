/*
1. 这个题只有两种优先级的操作符，所以可以很容易做出来
2. 要注意字符为空字符的情况
3. 要注意字符串结束的情况
*/
class Solution {
public:
    int calculate(string s) {
        if (s.size() == 0) return 0;
        stack<int> st;
        char lastSign = '+';
        int num = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isDigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            if ((!isDigit(s[i]) && s[i] != ' ' ) || i == s.size() - 1) {
                if (lastSign == '+') {
                    st.push(num);
                } else if (lastSign == '-') {
                    st.push(num * -1);
                } else if (lastSign == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top * num);
                } else if (lastSign == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top / num);
                }
                lastSign = s[i];
                num = 0;
            }
        }

        int res = 0;
        while (!st.empty()) {
            int top = st.top();
            st.pop();
            res += top;
        }
        return res;
    }

    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
};
