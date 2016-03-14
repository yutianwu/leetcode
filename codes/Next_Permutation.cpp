class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 0) return;

        int bigger = nums.size() - 1, target = bigger - 1;
        for (target; target >= 0; target--) {
            if (nums[bigger] <= nums[target])
                bigger = target;
            else
                break;
        }

        if (target == -1) {
            sort(nums.begin(), nums.end());
        } else {
            while (bigger + 1 < nums.size() && nums[bigger + 1] > nums[target]) bigger += 1;
            swap(nums[bigger], nums[target]);
            sort(nums.begin() + target + 1, nums.end());
        }
    }
};
