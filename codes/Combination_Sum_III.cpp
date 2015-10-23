class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> results;
        vector<int> result;
        dfs(results, result, 1, k, n);
        return results;
    }
    
    void dfs(vector<vector<int>> &results, vector<int> &result, int cur, int k, int n) {
        int size = result.size();
        int sum = 0;
        for (int i = 0; i < size; i++) 
            sum += result[i];
            
        if (size == k && sum == n) {
            results.push_back(result);
            return;
        }
        
        if (size < k && sum < n) {
            for (int i = cur; i <= n - k + 1 && i <= 9; i++) {
                if (sum + i <= n) {
                    result.push_back(i);
                    dfs(results, result, i + 1, k, n);
                    result.pop_back();
                }
            }
        }
    }
};