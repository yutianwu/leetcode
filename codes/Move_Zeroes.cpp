/**
此题解法比较简单，使用的是双指针的思想，用一个指针标注第一个0的位置，用一个指针标注第一个非零数字的位置
先找到第一个0的位置，然后找在0后面的第一个非零位，交换，然后继续
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int zeroPointer = 0;
        int numPointer = -1;
        while (numPointer < size && zeroPointer < (size - 1)) {
            for (zeroPointer; zeroPointer < size; zeroPointer++) {
                if (nums[zeroPointer] == 0) 
                    break;
            }
            
            numPointer =  zeroPointer + 1;
            for (numPointer; numPointer < size; numPointer++) {
                if (nums[numPointer] != 0)
                    break;
            }
            
            if (numPointer < size) {
                swap(nums[numPointer], nums[zeroPointer]);
            }
            zeroPointer = zeroPointer > numPointer ? numPointer : zeroPointer;
        }
    }
};