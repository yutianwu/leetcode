class Solution {
public:
    bool isPalindrome(string str) {
        if (str.size() <= 1) return true;
        int s = 0, e = str.size() - 1;
        while (s < e) {
            if (str[s++] != str[e--]) return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        if (words.size() < 2) return {};
        vector<vector<int>> result;
        map<string, int> dict;
        for (int i = 0; i < words.size(); i++)
            dict[words[i]] = i;

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j <= words[i].size(); j++) {
                string prefix = words[i].substr(0, j);
                reverse(prefix.begin(), prefix.end());
                if (dict.find(prefix) != dict.end() && isPalindrome(words[i].substr(j, words[i].size() - j))) {
                    if (i != dict[prefix])
                        result.push_back({i, dict[prefix]});
                }

                string suffix = words[i].substr(words[i].size() - j, j);
                reverse(suffix.begin(), suffix.end());
                string left = words[i].substr(0, words[i].size() - j);
                if (dict.find(suffix) != dict.end() && isPalindrome(left)) {
                    if (i != dict[suffix] && words[i].size() > suffix.size())
                        result.push_back({dict[suffix], i});
                }
            }
        }
        return result;
    }

};
