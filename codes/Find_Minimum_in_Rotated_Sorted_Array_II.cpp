class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1, ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < nums[end]) {
                if (ans == -1 || nums[ans] > nums[mid]) ans = mid;
                end = mid - 1;
            } else if (nums[mid] > nums[end]) {
                start = mid + 1;
            } else {
                if (ans == -1 || nums[ans] > nums[mid]) ans = mid;
                end -= 1;
            }
        }
        return nums[ans];
    }
};
