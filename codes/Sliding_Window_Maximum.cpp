class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() < k) return {};
        vector<int> result;
        deque<int> aux;
        for (int i = 0; i < nums.size(); i++) {
            if (aux.empty() || nums[i] <= nums[aux.back()]) {
                aux.push_back(i);
            } else {
                while (!aux.empty() && nums[i] > nums[aux.back()])
                    aux.pop_back();
                aux.push_back(i);
            }
            while (!aux.empty() && i - aux.front() >= k)
                aux.pop_front();
            if (i >= k - 1)
                result.push_back(nums[aux.front()]);
        }
        return result;
    }
};
