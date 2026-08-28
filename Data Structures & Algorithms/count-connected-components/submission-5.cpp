class Solution {
public:
    void dfs( vector<vector<int>>& adj,int idx,vector<int> &vis)
    {
        vis[idx]=1;

        for(auto neib:adj[idx])
        {
            if(!vis[neib])
        {
            dfs(adj,neib,vis);
        }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        int count=0;

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(adj,i,vis);
            }
        }
        return count;

    }
};
