class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> dict;
        for (int i = 0; i < strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (dict.find(tmp) != dict.end()) {
                result[dict[tmp]].push_back(strs[i]);
            } else {
                dict[tmp] = result.size();
                vector<string> row;
                row.push_back(strs[i]);
                result.push_back(row);
            }
        }

        for (int i = 0; i < result.size(); i++)
            sort(result[i].begin(), result[i].end());

        return result;
    }
};
