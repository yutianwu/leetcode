/*
这个题很容易想到使用一个map解决问题，时间复杂度为O(n)，但是使用string做键值，空间复杂度比较高

但是考虑到字母数量比较少，而且字符串长度也固定，所以可以对字符串进行编码

A => 00
C => 01
T => 10
G => 11

然后10个字符的话20位就可以搞定，还不到一个int的长度，good
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<int, int> dict;
        vector <string> result;
        
        for (int i = 0; i <= (int)s.size() - 10; i++) {
            string tmp = s.substr(i, 10);
            int code = transform(tmp);
            if (dict.count(code))
                dict[code] += 1;
            else
                dict.insert(make_pair(code, 1));
            
            if(dict[code] == 2)
                result.push_back(tmp);
        }
        
        return result;
    }
    
    int getRelatedDigits(char c) {
        switch (c) {
            case 'A':
                return 0; //"00"
            case 'C':
                return 1; //"01"
            case 'T':
                return 2; //"10"
            case 'G':
                return 3; //"11"
            default:
                return 0; //"00"
        }
    }
    
    int transform(string str) {
        int result = 0;
        for (int i = 0; i < 10; i++) {
            int digits = getRelatedDigits(str[i]);
            result |= digits;
            result <<= 2;
        }
        result >>= 2;
        return result;
    }
};