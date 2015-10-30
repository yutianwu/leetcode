/**
基本思路就是从高位往低位找如果找到不一样就跳出
比如7和5
0111
0101
从左往右第二位是一样， 第三位不一样就跳出
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int result = 0;
        for (int i = 31; i >= 0; i--) {
            int mm = m >> i & 1;
            int nn = n >> i & 1;
            if (mm == nn && mm == 1)
                result += 1 << i;
            else if (mm != nn)
                break;
        }
        return result;
    }
};