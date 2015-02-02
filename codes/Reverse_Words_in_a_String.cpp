class Solution {
public:
    void reverseWords(string &s) {
        if (s.size() == 0) return;
        
        stack<string> res;
        int pos = 0;
        int len = 0;
        
        while (pos < s.size()) {
            if (s[pos] != ' ') {
                len++;
                pos++;
            } else {
                if (len > 0)
                    res.push(s.substr(pos - len, len) + " ");
                
                len = 0;
                pos++;
            }
        }
        if (len > 0)
            res.push(s.substr(pos - len, len) + " ");
            
        string tmp = "";
        while (!res.empty()) {
            string s_top = res.top();
            res.pop();
            tmp += s_top;
        }
        s = tmp;
        if (s.size() > 0) {
            s.erase(s.size() - 1, 1);
        }
    }
};