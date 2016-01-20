class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int begin = -1, end = nums.size() - 1;
        while (end - begin > 1) {
            int mid = begin + (end - begin) / 2;
            if (nums[mid] < nums[end]) end = mid;
            else begin = mid;
        }
        return nums[end];
    }
};
