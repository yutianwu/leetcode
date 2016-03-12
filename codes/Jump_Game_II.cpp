// 计算最少步数的方法，还是用BFS好
class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0, end = 0, steps = 0;
        while (end < nums.size() - 1) {
            int farest = end;
            for (int i = start; i <= end; i++)
                farest = max(farest, i + nums[i]);
            start = end + 1;
            end = farest;
            steps += 1;
        }
        return steps;
    }
};
