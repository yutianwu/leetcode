class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int pre = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[pre])
                nums[++pre] = nums[i];
        }
        return pre + 1;
    }
};
