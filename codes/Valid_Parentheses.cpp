class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (st.empty()) st.push(s[i]);
            else {
                if (isMatch(st.top(), s[i]))
                    st.pop();
                else if (isLeft(s[i]) && isLeft(st.top()))
                    st.push(s[i]);
                else
                    return false;
            }
        }
        return st.empty() ? true : false;
    }

    bool isMatch(char a, char b) {
        if (a == '(' && b == ')') return true;
        if (a == '[' && b == ']') return true;
        if (a == '{' && b == '}') return true;
        return false;
    }

    bool isLeft(char a) {
        if (a == '(' || a == '[' || a == '{') return true;
        return false;
    }
};
