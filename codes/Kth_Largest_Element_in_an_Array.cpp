class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int> > que;
        for (int i = 0; i < nums.size(); i++) {
            que.push(nums[i]);
        }
        
        for (int i = 1; i < k; i++) {
            que.pop();
        }
        return que.top();
    }
};