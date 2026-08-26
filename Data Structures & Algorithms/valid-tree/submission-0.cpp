class Solution {
        public:
            bool dfs(int node, int parent, vector<vector<int>>& graph, vector<bool>& vis)
                {
                        vis[node] = true;

                                for(int next : graph[node])
                                        {
                                                    if(next == parent)
                                                                    continue;

                                                                                if(vis[next])
                                                                                                return false;

                                                                                                            if(!dfs(next, node, graph, vis))
                                                                                                                            return false;
                                                                                                                                    }

                                                                                                                                            return true;
                                                                                                                                                }

                                                                                                                                                    bool validTree(int n, vector<vector<int>>& edges)
                                                                                                                                                        {
                                                                                                                                                                // A tree with n nodes must have exactly n-1 edges
                                                                                                                                                                        if(edges.size() != n - 1)
                                                                                                                                                                                    return false;

                                                                                                                                                                                            vector<vector<int>> graph(n);

                                                                                                                                                                                                    for(auto edge : edges)
                                                                                                                                                                                                            {
                                                                                                                                                                                                                        int u = edge[0];
                                                                                                                                                                                                                                    int v = edge[1];

                                                                                                                                                                                                                                                graph[u].push_back(v);
                                                                                                                                                                                                                                                            graph[v].push_back(u);
                                                                                                                                                                                                                                                                    }

                                                                                                                                                                                                                                                                            vector<bool> vis(n, false);

                                                                                                                                                                                                                                                                                    // Check for cycle
                                                                                                                                                                                                                                                                                            if(!dfs(0, -1, graph, vis))
                                                                                                                                                                                                                                                                                                        return false;

                                                                                                                                                                                                                                                                                                                // Check that every node is connected
                                                                                                                                                                                                                                                                                                                        for(int i = 0; i < n; i++)
                                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                                            if(!vis[i])
                                                                                                                                                                                                                                                                                                                                                            return false;
                                                                                                                                                                                                                                                                                                                                                                    }

                                                                                                                                                                                                                                                                                                                                                                            return true;
                                                                                                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                                                        };

