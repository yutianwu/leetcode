class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        if (tickets.size() == 0) return {};
        map<string, multiset<string>> graph;
        for (int i = 0; i < tickets.size(); i++)
            graph[tickets[i].first].insert(tickets[i].second);

        vector<string> result;
        dfs("JFK", result, graph);
        return vector<string>(result.rbegin(), result.rend());
    }

    void dfs(string from, vector<string> &result, map<string, multiset<string>> &graph) {
        while (graph[from].size() > 0) {
            string to = *graph[from].begin();
            graph[from].erase(graph[from].begin());
            dfs(to, result, graph);
        }
        result.push_back(from); // 如果到一个点走不下去了，那这个点就是终点了
    }
};
