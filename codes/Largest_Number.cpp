/*
1.在这里需要注意to_string函数的应用，可以直接将int转换成string

2.本题思路就是首先将所有int转换成string，然后排序，
排序的原则就是给定string a和b，如果a+b > b+a,则a > b

3.有点需要注意的是所有元素都是0的时候的情形
*/

class Solution {
public:
    static bool myComp(string a, string b) {
        string c1 = a + b;
        string c2 = b + a;
        return c1 > c2;        
    }

    string largestNumber(vector<int> &num) {
        if (num.size() == 0) return "";
        vector<string> num_str;
        for (int i = 0; i < num.size(); ++i) {
            num_str.push_back(to_string(num[i]));
        }
        sort(num_str.begin(), num_str.end(), Solution::myComp);
        string res1 = "";
        for (int i = 0; i < num_str.size(); ++i)
            res1 += num_str[i];
        
        //如果全为零的话，要将答案置零
        if (res1[0] == '0')
            return "0";
        else
            return res1;
    }
};
