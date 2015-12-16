class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int globalMax = nums[0];
        int localMax = nums[0], localMin = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int tmpMax = localMax, tmpMin = localMin;
            localMax = max(nums[i], max(tmpMax * nums[i], tmpMin * nums[i]));
            localMin = min(nums[i], min(tmpMax * nums[i], tmpMin * nums[i]));
            globalMax = max(globalMax, localMax);
        }
        return globalMax;
    }
};
