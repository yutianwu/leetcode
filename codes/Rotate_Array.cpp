/*
  简单解法，使用一个辅助数组，需要使用O(n)的时间复杂度和空间复杂度
*/
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k = k % n;
        
        int *tmp = new int[n];
        
        for (int i = 0; i < k; i++) 
            tmp[i] = nums[n - k + i];
        
        for (int i = 0; i < n - k; i++) 
            nums[n - 1 - i] = nums[n - k - 1 - i];
        
        for (int i = 0; i < k; i++) 
            nums[i] = tmp[i];
        
        delete tmp;
    }
};


/*
  比较有技巧性的解法，我们发现，其实我们只要先将整个数组倒过来，
  然后分别将前k个和后n-k个数倒过来就可以了
*/
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k = k % n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
    
    void reverse(int nums[], int start, int end) {
        int length = end - start + 1;
        
        if (length < 2) return;
        for (int i = 0; i < length / 2; i++) {
            int tmp = nums[start + i];
            nums[start + i] = nums[end - i];
            nums[end - i] = tmp;
        }
    }
};