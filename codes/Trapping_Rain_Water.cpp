class Solution {
public:
    int trap(vector<int>& height) {
        int highest = 0, index = 0;
        for (int i = 0; i < height.size(); i++) {
            if (highest < height[i]) {
                highest = height[i];
                index = i;
            }
        }

        int result = 0, left = 0, right = 0;
        for (int i = 0; i < index; i++) {
            if (height[i] < left && height[i] < highest)
                result += min(highest, left) - height[i];
            left = max(left, height[i]);
        }

        for (int i = height.size() - 1; i > index; i--) {
            if (height[i] < right && height[i] < highest)
                result += min(right, highest) - height[i];
            right = max(height[i], right);
        }
        return result;
    }
};
