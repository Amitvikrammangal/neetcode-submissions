class Solution {
public:
    bool dfs(vector<vector<int>> adj,vector<int>& vis,int idx,int parent)
    {
        vis[idx]=1;

        for(auto neib:adj[idx])
        {
            if(!vis[neib])
            {
                if(dfs(adj,vis,neib,idx))
                return true;
            }
            else if(parent!=neib)
            return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        if(edges.size() != n-1)
            return false;
            
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(dfs(adj,vis,i,-1)==true)
                return false;
            }
        }
        return true;
    }
};
