class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> table;
        for (int i = 0 ; i < nums.size(); i++) {
            if (table.find(nums[i]) == table.end())
                table[nums[i]] = i;
            else {
                int last =  table[nums[i]];
                if (i - last <= k)  
                    return true;
                else 
                    table[nums[i]] = i;
            }
        }
        return false;
    }
};