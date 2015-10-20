class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), [](int a, int b) {
            return b < a;
        });
        int i = 0;
        for (; i < citations.size(); i++) {
            if (citations[i] < i + 1)
                break;
        }
        return i;
    }
};