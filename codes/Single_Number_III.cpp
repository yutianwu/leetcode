
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int first = 0, second = 0;
        
        int two = 0;
        for (int i = 0; i < nums.size(); i++) {
            two ^= nums[i];
        }
        
        /**
            下面找出第一个1的位置，这个位置也是两个数不一样的地方之一，
            现在可以根据数组中数在这个位置上是否为1分为两组，那么两组各含有两个数中的一个，再使用
            前面的方法就可以找出这两个数了
        */
        int cmp = two & (two - 1) ^ two; 
        for (int i = 0; i < nums.size(); i++) {
            if (cmp & nums[i]) 
                first ^= nums[i];
            else 
                second ^= nums[i];
        }
        return vector<int>{first, second};
    }
};