/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        map<int, UndirectedGraphNode *> dict;
        set<int> visited;
        return cloneGraph(node, dict, visited);
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node, map<int, UndirectedGraphNode *> &dict, set<int> &visited) {
        UndirectedGraphNode *root;
        if (dict.find(node->label) != dict.end()) {
            root = dict[node->label];
        } else {
            root = new UndirectedGraphNode(node->label);
            dict[node->label] = root;
        }

        for (int i = 0; i < node->neighbors.size(); i++) {
            UndirectedGraphNode *tmp = node->neighbors[i];
            if (dict.find(tmp->label) != dict.end()) {
                root->neighbors.push_back(dict[tmp->label]);
            } else {
                UndirectedGraphNode *newNode = new UndirectedGraphNode(tmp->label);
                root->neighbors.push_back(newNode);
                dict[tmp->label] = newNode;
            }
        }

        visited.insert(node->label);
        for (int i = 0; i < node->neighbors.size(); i++) {
            if (visited.count(node->neighbors[i]->label) == 0)
                cloneGraph(node->neighbors[i], dict, visited);
        }
        return root;
    }
};
