class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int front = i + 1, back = nums.size() - 1;
            while (front < back) {
                int sum = nums[i] + nums[front] + nums[back];
                if (sum > 0) {
                    back--;
                } else if (sum < 0) {
                    front++;
                } else {
                    vector<int> row;
                    row.push_back(nums[i]);
                    row.push_back(nums[front]);
                    row.push_back(nums[back]);
                    result.push_back(row);

                    while (front < back && nums[front] == row[1]) front++;
                    while (front < back && nums[back] == row[2]) back--;
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
    }
};
