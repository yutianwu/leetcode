class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size(), len2 = needle.size();
        for (int i = 0; i <= len1 - len2; i++) {
            int cur = i, j = 0;
            for (j; j < len2; j++) {
                if (haystack[cur++] != needle[j]) break;
            }
            if (j == len2) return i;
        }
        return -1;
    }
};
