class Solution {
public:
    int maxArea(vector<int>& height) {
        int front = 0, back = height.size() - 1, result = 0;
        while (front < back) {
            result = max(result, min(height[front], height[back]) * (back - front));
            if (height[front] <= height[back])
                front++;
            else
                back--;
        }
        return result;
    }
};
