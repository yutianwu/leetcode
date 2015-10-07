class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long x = 0, y = 0;
        x = (long long)(G <= C ? G : C) - (A >= E ? A : E);
        y = (long long)(D <= H ? D : H) - (B >= F ? B : F);
        x = x >= 0 ? x : 0;
        y = y >= 0 ? y : 0;
        return (C - A) * (D - B) + (G - E) * (H - F) - x * y;
    }
};