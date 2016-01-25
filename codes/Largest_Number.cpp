/*
1.在这里需要注意to_string函数的应用，可以直接将int转换成string

2.本题思路就是首先将所有int转换成string，然后排序，
排序的原则就是给定string a和b，如果a+b > b+a,则a > b

3.有点需要注意的是所有元素都是0的时候的情形
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string result;
        sort(nums.begin(), nums.end(), cmp);
        for (int i = 0; i < nums.size(); i++)
            result += to_string(nums[i]);

        return (result.size() > 0 && result[0] == '0') ? "0" : result;
    }

    static bool cmp(const int &m, const int &n) {
        return to_string(m) + to_string(n) > to_string(n) + to_string(m);
    }
};
