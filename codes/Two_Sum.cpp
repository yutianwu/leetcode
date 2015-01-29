class Solution {
public:
    typedef pair<int, int> index_map;
    
    static bool cmp(const index_map &a, const index_map &b) {
        return a.first < b.first;
    }
    
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<index_map> new_array;
        new_array.reserve(numbers.size());
        
        for (int i = 0; i < numbers.size(); i++) 
            new_array.push_back(index_map(numbers[i], i + 1));
        
        sort(new_array.begin(), new_array.end(), cmp);
        
        int start = 0, end = new_array.size() - 1;
        while (start < end) {
            int sum = new_array[start].first + new_array[end].first;
            
            if (sum == target)
                break;
            else if (sum > target)
                end--;
            else 
                start++;
        }
        
        vector<int> result;
        if (start < end) {
            int index1 = new_array[start].second, index2 = new_array[end].second;
            result.push_back(min(index1, index2));
            result.push_back(max(index1, index2));
        }
        return result;
    }
};