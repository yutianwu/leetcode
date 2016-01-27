// 解法一，使用三个变量标记每一位上出现的次数

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, three = 0;
        for (int i = 0; i < nums.size(); i++) {
            three = two & nums[i];
            two |= one & nums[i];
            one ^= nums[i];
            two &= ~three;
            one &= ~three;
        }
        return one;
    }
};

// 解法二 通用解法
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        int bit[32] = {0};
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < nums.size(); j++)
                bit[i] += (nums[j] >> i) & 1;
            result |= (bit[i] % 3) << i;
        }
        return result;
    }
};
