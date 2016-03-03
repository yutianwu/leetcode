/*
如果一个数组中和可能的范围为[1,n),那么添加一个数，能够拓展的最大范围的就是n,添加n后，范围就
变成了[1, n + n).并且添加n后，n + n - 1中的每个数都是可能的，因为n - 1中的每个数都是可鞥的。
**/
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1;
        int i = 0, patch = 0;
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss += miss;
                patch++;
            }
        }
        return patch;
    }
};
