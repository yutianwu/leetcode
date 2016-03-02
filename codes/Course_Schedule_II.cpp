class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> result;

        if (numCourses == 0) return result;
        vector<vector<int>> graph(numCourses + 1, vector<int>());
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        }

        vector<bool> visited(numCourses + 1, false);
        vector<bool> path(numCourses + 1, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && dfs(i, result, path, visited, graph))
                return {};
        }
        return result;
    }

    bool dfs(int num, vector<int> &result, vector<bool> &path, vector<bool> &visited, vector<vector<int>> &graph) {
        if (visited[num]) return false;
        visited[num] = true;
        path[num] = true;
        for (int i = 0; i < graph[num].size(); i++) {
            if (path[graph[num][i]] || dfs(graph[num][i], result, path, visited, graph))
                return true;
        }
        result.insert(result.begin(), num);
        path[num] = false;
        return false;
    }
};
