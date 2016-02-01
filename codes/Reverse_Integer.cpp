/**
负数取余还是负数，所以不用关心负数的事，
同时要注意不要溢出
*/
class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x != 0) {
            if (abs(result) > INT_MAX / 10) return 0; // 防止溢出
            result = result * 10 + x % 10;
            x /= 10;
        }
        return result;
    }
};
