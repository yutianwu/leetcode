class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> table;
        map<char, char> set;
        for (int i = 0; i < s.size(); i++) {
            if (table.find(s[i]) != table.end()) {
                if (table[s[i]] != t[i])
                    return false;
            } else {
                if (set.find(t[i]) != set.end())
                    return false;
                else {
                    table[s[i]] = t[i];
                    set[t[i]] = s[i];
                }
            }
        }
        return true;
    }
};