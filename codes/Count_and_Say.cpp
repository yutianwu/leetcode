class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) return "";
        string result = "1";
        for (int i = 2; i <= n; i++) {
            string tmp;
            for (int j = 0; j < result.size(); ) {
                int count = 1;
                while (j + count < result.size() && result[j] == result[j + count])
                    count++;
                tmp += to_string(count) + result[j];
                j = j + count;
            }
            result = tmp;
        }
        return result;
    }
};
