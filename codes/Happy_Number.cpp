class Solution {
public:
    bool isHappy(int n) {
        map<int, int> table;
        while (true) {
            if (n == 1) return true;
            if (table.find(n) == table.end()) {
                table[n] = 1;
                int tmp = 0;
                while (n != 0) {
                    int remainer = n % 10;
                    tmp += remainer * remainer;
                    n = n / 10;
                }
                n = tmp;
            } else {
                return false;
            }
        }
    }
};