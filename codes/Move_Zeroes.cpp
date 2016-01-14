/**
此题解法比较简单，使用的是双指针的思想，用一个指针标注第一个0的位置，用一个指针标注第一个非零数字的位置
先找到第一个0的位置，然后找在0后面的第一个非零位，交换，然后继续
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() == 0) return;
        int cur = 0, last = 0;
        while (cur < nums.size()) {
            if (nums[cur] != 0) {
                swap(nums[cur], nums[last]);
                last++;
            }
            cur++;
        }
    }
};
