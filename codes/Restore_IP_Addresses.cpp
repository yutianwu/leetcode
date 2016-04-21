class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> ip;
        dfs(s, 0, ip, result);
        return result;
    }

    void dfs(string s, int pos, vector<string> &ip, vector<string> &result) {
        if (pos >= s.size()) {
            if (ip.size() == 4) {
                string tmp = ip[0] + "." + ip[1] + "." + ip[2] + "." + ip[3];
                result.push_back(tmp);
            }
            return;
        }

        if (s.size() - pos < (4 - ip.size())) return;
        if (s.size() - pos > 3 * (4 - ip.size())) return;

        int num = 0;
        for (int i = pos; i < 3 + pos && i < s.size(); i++) {
            num = num * 10 + (s[i] - '0');
            if (num > 255) break;
            ip.push_back(s.substr(pos, i - pos + 1));
            dfs(s, i + 1, ip, result);
            ip.pop_back();
            if (num == 0) break;
        }
    }
};
