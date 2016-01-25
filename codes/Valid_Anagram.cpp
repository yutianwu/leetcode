class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        map<char, int> hash;
        for (int i = 0; i < s.size(); i++) {
            char tmp = s[i];
            if (hash.find(tmp) != hash.end())
                hash[tmp]++;
            else
                hash[tmp] = 1;
        }

        for (int i = 0; i < t.size(); i++) {
            char tmp = t[i];
            if (hash.find(tmp) != hash.end()) {
                hash[tmp]--;
                if (hash[tmp] < 0)
                    return false;
            } else {
                return false;
            }
        }
        return true;
    }
};

// 解法二 排序
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<char> vs, vt;
        for (int i = 0; i < s.size(); i++) {
            vs.push_back(s[i]);
            vt.push_back(t[i]);
        }

        sort(vs.begin(), vs.end());
        sort(vt.begin(), vt.end());
        for (int i = 0; i < vs.size(); i++) {
            if (vs[i] != vt[i]) return false;
        }
        return true;
    }
};
