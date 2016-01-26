class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1, 1);
        for (int i = 2; i <= rowIndex; i++) {
            int last = result[0];
            for (int j = 1; j < i; j++) {
                int tmp = result[j];
                result[j] = last + result[j];
                last = tmp;
            }
        }
        return result;
    }
};
