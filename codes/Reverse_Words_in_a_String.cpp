class Solution {
public:
    void reverseWords(string &s) {
        if (s.size() == 0) return;
        int start = 0, cur = 0;

        while (true) {
            while (cur < s.size() && s[cur] == ' ') cur++;
            if (cur == s.size()) break;

            if (start != 0) s[start++] = ' '; //特别注意在这里插入一个空格，条件要对
            int tmp = start;
            while (cur < s.size() && s[cur] != ' ')
                s[start++] = s[cur++];
            reverse(s.begin() + tmp, s.begin() + start);
        }

        s.resize(start);
        reverse(s.begin(), s.end());
    }
};
