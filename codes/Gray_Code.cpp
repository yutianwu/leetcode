// 解法一，这种解法比较简单，但是得能够看出格雷码的规律

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1, 0);
        for (int i = 0; i < n; i++) {
            int cur = result.size();
            while (cur) {
                cur--;
                result.push_back(result[cur] + (1 << i));
            }
        }
        return result;
    }
};

// 解法二 回溯法
class Solution {
public:
    int Bit2Int(bitset<32> &c, int n)
    {
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum <<= 1;
            sum += c[i];
        }
        return sum;
    }

    void backtrack(bitset<32> &c, int k, int n, vector<int> &result)
    {
        if(++k == n)
            result.push_back(Bit2Int(c, n));
        else
        {
            backtrack(c, k, n, result);
            c.flip(k);
            backtrack(c, k, n, result);
        }
    }

    vector<int> grayCode(int n) {
        vector<int> result;
        bitset<32> c;
        backtrack(c, -1, n, result);
        return result;
    }
};
