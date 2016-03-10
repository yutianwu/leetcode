class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) return {0}; // 考虑只有一个点的情况

        vector<set<int>> graph(n, set<int>());
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i].first].insert(edges[i].second);
            graph[edges[i].second].insert(edges[i].first);
        }

        vector<int> leafs;
        for (int i = 0; i < n; i++) {
            if (graph[i].size() <= 1)
                leafs.push_back(i);
        }

        while (n > 2) {
            n -= leafs.size();
            vector<int> newLeafs;
            for (int i = 0; i < leafs.size(); i++) {
                int adj = *graph[leafs[i]].begin();
                graph[adj].erase(leafs[i]);
                if (graph[adj].size() == 1)
                    newLeafs.push_back(adj);
            }
            leafs = newLeafs;
        }
        return leafs;
    }
};
