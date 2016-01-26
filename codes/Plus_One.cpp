class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int over = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int num = digits[i] + over;
            over = num / 10;
            num = num % 10;
            digits[i] = num;
        }
        if (over != 0)
            digits.insert(digits.begin(), over);

        return digits;
    }
};
