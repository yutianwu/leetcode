class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> dict;
        while (n != 1) {
            n = digitSquare(n);
            if (dict.find(n) != dict.end()) break;
            dict.insert(n);
        }
        return n == 1 ? true : false;
    }

    int digitSquare(int n) {
        int sum = 0;
        while (n) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }
};
