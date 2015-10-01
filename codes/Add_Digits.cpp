/**
	此题技巧性比较强，详细解答见博客
*/
class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};