class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p0 = m - 1, p1 = n - 1;
        for (int i = m + n - 1; i >= 0; i--) {
            if (p0 < 0) {
                nums1[i] = nums2[p1--];
            } else if (p1 < 0) {
                nums1[i] = nums1[p0--];
            } else if (nums1[p0] >= nums2[p1]) {
                nums1[i] = nums1[p0--];
            } else {
                nums1[i] = nums2[p1--];
            }
        }
    }
};
