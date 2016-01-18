class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int begin = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (begin - 1 < 0 || nums[begin - 1] != nums[i])
                nums[++begin] = nums[i];
        }
        return nums.size() == 0 ? 0 : begin + 1;
    }
};
