// The idea is to sweep all 0s to the left and all 2s to the right, then all 1s are left in the middle.
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int begin = 0, back = nums.size() - 1;
        for (int i = begin; i <= back; i++) {
            while (nums[i] == 2 && i < back) {
                swap(nums[i], nums[back--]);
            }
            while (nums[i] == 0 && i > begin) {
                swap(nums[i], nums[begin++]);
            }
        }
    }
};
