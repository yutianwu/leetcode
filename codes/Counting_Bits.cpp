/**
利用以前的结果，其实A[i]的值就是A[i&(i - 1)] + 1，
意思是把i的最后一个一去掉，这是的到的数是i & (i - 1)，而i > i & (i - 1);
而且A[i]比A[i & (i - 1)]多了一个1，就是去掉的那个
**/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};
