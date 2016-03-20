class Solution {
public:
    int trailingZeroes(int n) {
        if (n <= 0) return 0;
        int nums = 0;
        while (n / 5 > 0) {
            nums += n / 5;
            n /= 5;
        }
        return nums;
    }
};
