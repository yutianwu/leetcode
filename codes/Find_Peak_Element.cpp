class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        int low = 0, high = size;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(mid + 1 < size && nums[mid] < nums[mid + 1])    low = mid+1;
            else if(mid >= 1 && nums[mid] < nums[mid - 1])   high = mid;
            else return mid; 
        }
        return low;
    }
};