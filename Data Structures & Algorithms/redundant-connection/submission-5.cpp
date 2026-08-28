class Solution {
public:

    bool dfs(int node, int parent,
             vector<vector<int>>& graph,
             vector<bool>& vis) {

        vis[node] = true;

        for (int neigh : graph[node]) {

            // First: if not visited, go there
            if (!vis[neigh]) {

                if (dfs(neigh, node, graph, vis))
                    return true;
            }

            // Then: if already visited and not parent
            else if (neigh != parent) {
                return true;
            }
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

            if (dfs(u, -1, graph, vis)) {
                return edge;
            }
        }

        return {};
    }
};