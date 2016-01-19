class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> alpha;
        int front = 0, len = 0;
        for (int back = 0; back < s.size(); back++) {
            if (alpha.find(s[back]) != alpha.end())
                alpha[s[back]] += 1;
            else
                alpha[s[back]] = 1;

            while (alpha[s[back]] >= 2)
                alpha[s[front++]] -= 1;

            len = max(len, back - front + 1);
        }
        return len;
    }
};
