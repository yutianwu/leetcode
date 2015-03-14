class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for (int i = 0; i < 16; i++) {
            int front = (n >> (31 - i)) & 1, end = (n >> i) & 1;
            n = n & ~(1 << i) & ~(1 << (31 - i));
            n = n | (end << (31 - i)) | (front << i);
        }
        return n;
    }
};