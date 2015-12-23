class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int N = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        // rangeValues[i][j] is the maximum # of coins that can be obtained
        // by popping balloons only in the range [i,j]
        vector<vector<int>> rangeValues(nums.size(), vector<int>(nums.size(), 0));

        // build up from shorter ranges to longer ranges
        for (int len = 1; len <= N; ++len) {
            for (int start = 1; start <= N - len + 1; ++start) {
                int end = start + len - 1;
                // calculate the max # of coins that can be obtained by
                // popping balloons only in the range [start,end].
                // consider all possible choices of final balloon to pop
                for (int final = start; final <= end; ++final) {
                    rangeValues[start][end] = max(rangeValues[start][end], rangeValues[start][final-1] + nums[start-1] * nums[final] * nums[end+1] + rangeValues[final+1][end]);
                }
            }
        }
        return rangeValues[1][N];
    }
};
