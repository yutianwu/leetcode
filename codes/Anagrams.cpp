/*
思路就是先对每一个字符串进行排序，然后用这个排完序的字符串做字典的索引，
这样的话只要是字母相同的单词就会放入同一组里

这里需要注意的是，排序并不需要自己写算法排序，只需要调用排序算法就好了，
以后做题时可以注意一下
*/

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) { 
        unordered_map<string, vector<string> > group;
        for (const auto &s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            group[key].push_back(s);
        }
        
        vector<string> result;
        for (auto it = group.cbegin(); it != group.cend(); it++) {
            if (it->second.size() > 1) 
                result.insert(result.end(), it->second.begin(), it->second.end());
        }
        return result;
    }
};