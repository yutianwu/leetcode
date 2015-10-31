/**
滑动窗口
*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int head = 0;
        int sum = 0;
        int res = INT_MAX;
        for (int tail = 0; tail < nums.size(); tail++) {
            sum += nums[tail];
            if (sum >= s) {
                while (sum - nums[head] >= s) {
                    sum -= nums[head];
                    head += 1;
                }
                res = min(res, tail - head + 1);
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};