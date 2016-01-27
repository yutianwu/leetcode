class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, char> st, ts;
        for (int i = 0; i < s.size(); i++) {
            if (st.find(s[i]) != st.end() && ts.find(t[i]) != ts.end()) {
                if (s[i] != ts[t[i]] || t[i] != st[s[i]]) return false;
            } else if (st.find(s[i]) != st.end() || ts.find(t[i]) != ts.end()) {
                return false;
            } else {
                st[s[i]] = t[i];
                ts[t[i]] = s[i];
            }
        }
        return true;
    }
};


// 解法二
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        int st[256] = {0}, ts[256] = {0};
        for (int i = 0; i < s.size(); i++) {
            if (st[s[i]] != ts[t[i]]) return false;
            st[s[i]] = i + 1;
            ts[t[i]] = i + 1;
        }
        return true;
    }
};
