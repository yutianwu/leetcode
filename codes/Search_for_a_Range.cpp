class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int begin = -1, end = nums.size();
        while (begin + 1 < end) {
            int mid = begin + (end - begin) / 2;
            if (nums[mid] < target)
                begin = mid;
            else
                end = mid;
        }
        int low = begin + 1;
        begin = -1;
        end = nums.size();
        while (begin + 1 < end) {
            int mid = begin + (end - begin) / 2;
            if (nums[mid] > target)
                end = mid;
            else
                begin = mid;
        }
        int high = end - 1;
        vector<int> result;
        if (high < low) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        } else {
            result.push_back(low);
            result.push_back(high);
            return result;
        }
    }
};
