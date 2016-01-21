class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int rows = matrix.size(), cols = matrix[0].size();
        int begin = -1, end = rows;
        while (end - begin > 1) {
            int mid = begin + (end - begin) / 2;
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] > target) end = mid;
            else begin = mid;
        }

        int row = end - 1;
        if (row < 0) return false;
        begin = 0, end = cols - 1;
        while (begin <= end) {
            int mid = begin + (end - begin) / 2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] > target) end = mid - 1;
            else begin = mid + 1;
        }
        return false;
    }
};
