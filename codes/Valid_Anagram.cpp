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