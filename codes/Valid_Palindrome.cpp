class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0) return true;
        int begin = 0, end = s.size() - 1;
        while (begin <= end) {
            if (!isChar(s[begin]))
                begin++;
            else  if (!isChar(s[end]))
                end--;
            else {
                if (!isEqual(s[begin], s[end]))
                    return false;
                begin++;
                end--;
            }
        }
        return true;
    }
    bool isChar(char c) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) return true;
        else false;
    }
    bool isEqual(char c1, char c2) {
        if (c1 >= '0' && c1 <= '9') {
            return c1 == c2 ? true : false;
        } else {
            if (c1 >= 'A' && c1 <= 'Z') c1 = 'a' + (c1 - 'A');
            if (c2 >= 'A' && c2 <= 'Z') c2 = 'a' + (c2 - 'A');
            return c1 == c2 ? true : false;
        }
    }
};
