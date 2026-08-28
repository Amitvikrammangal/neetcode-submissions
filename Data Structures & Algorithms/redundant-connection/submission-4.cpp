class Solution {
public:

    bool dfs(int node, int parent, vector<vector<int>>& graph,
             vector<bool>& vis) {

        vis[node] = true;

        for (int neigh : graph[node]) {

            // Parent is not a cycle
            if (neigh == parent)
                continue;

            // Already visited -> cycle
            if (vis[neigh])
                return true;

            if (dfs(neigh, node, graph, vis))
                return true;
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<vector<int>> graph(n + 1);

        for (auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);

            vector<bool> vis(n + 1, false);

            // Check whether adding this edge creates a cycle
            if (dfs(u, -1, graph, vis)) {
                return edge;
            }
        }

        return {};
    }
};