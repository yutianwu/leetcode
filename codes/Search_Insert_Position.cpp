class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = -1, end = nums.size();
        while (end - begin > 1) {
            int mid = begin + (end - begin) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) end = mid;
            else begin = mid;
        }
        return end;
    }
};
