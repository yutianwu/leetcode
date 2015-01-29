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
