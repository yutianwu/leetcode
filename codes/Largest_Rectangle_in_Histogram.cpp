class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0) return 0;
        heights.push_back(0);
        int result = 0, size = heights.size();
        stack<int> st;
        for (int i = 0; i < size; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int cur = st.top(), pre = cur;
                st.pop();
                if (st.empty()) pre = 0;
                else
                    pre = st.top() + 1;
                result = max(result, (i - pre) * heights[cur]);
            }
            st.push(i);
        }
        return result;
    }
};
