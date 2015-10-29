class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];
        
        vector<int> withOne(size, 0);
        vector<int> withOutOne(size, 0);
        withOne[0] = nums[0];
        withOne[1] = nums[0];
        
        withOutOne[0] = 0;
        withOutOne[1] = nums[1];
        
        for (int i = 2; i < size; i++) {
            withOne[i] = max(withOne[i - 1], nums[i] + withOne[i - 2]);
            withOutOne[i] = max(withOutOne[i - 1], nums[i] + withOutOne[i - 2]);
        }
        return max(withOne[size - 2], withOutOne[size - 1]);
    }
};