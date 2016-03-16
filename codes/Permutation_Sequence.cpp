class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";
        vector<int> nums;
        for (int i = 1; i <= n; i++) nums.push_back(i);

        for (int i = n; i > 0; i--) {
            int tmp = fac(i - 1);
            int pos = k / tmp;
            if (k % tmp > 0) pos += 1;
            s += to_string(nums[pos - 1]);
            nums.erase(nums.begin() + pos - 1);
            k = k - (pos - 1) * tmp;
        }
        return s;
    }

    int fac(int n) {
        if (n <= 1) return 1;
        int res = 1;
        for (int i = 2; i <= n; i++) {
            res *= i;
        }
        return res;
    }
};
