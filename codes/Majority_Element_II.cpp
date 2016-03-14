class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size() == 0) return {};
        int n1 = 0, n2 = 1, c1 = 0, c2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (n1 == nums[i]) {
                c1++;
            } else if (n2 == nums[i]) {
                c2++;
            } else if (c1 == 0) {
                n1 = nums[i];
                c1 = 1;
            } else if (c2 == 0) {
                n2 = nums[i];
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }
        c1 = 0;
        c2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (n1 == nums[i]) c1++;
            else if (n2 == nums[i]) c2++;
        }

        vector<int> result;
        if (c1 > nums.size() / 3) result.push_back(n1);
        if (c2 > nums.size() / 3) result.push_back(n2);
        return result;
    }
};
