class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses == 0) return true;
        vector<vector<int>> graph(numCourses + 1, vector<int>());
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i].first].push_back(prerequisites[i].second);
        }

        vector<bool> visited(numCourses + 1, false);
        for (int i = 0; i < numCourses; i++) {
            if (hasCycle(i, visited, graph))
                return false;
        }
        return true;
    }

    bool hasCycle(int num, vector<bool> &visited, vector<vector<int>> &graph) {
        visited[num] = true;
        for (int i = 0; i < graph[num].size(); i++) {
            int next = graph[num][i];
            if (visited[next])
                return true;
            else {
                visited[next] = true;
                bool tmp = hasCycle(next, visited, graph);
                if (tmp) return true;
                visited[next] = false;
            }
        }
        visited[num] = false;
        return false;
    }
};
