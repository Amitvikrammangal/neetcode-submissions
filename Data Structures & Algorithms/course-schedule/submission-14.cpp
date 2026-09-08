class Solution {
public:
    bool dfs( vector<vector<int>>& adj,vector<int> &vis,vector<int> &path,int i)
    {
        vis[i]=1;
        path[i]=1;
        for(auto neib:adj[i])
        {
            if(!vis[neib])
            {
                if(dfs(adj,vis,path,neib)==1)
                return true;
            }
            else if(path[neib]==1)
              return true;
        }
        path[i]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> vis(n+1,0);
        vector<int> path(n+1,0);

        for(auto x:prerequisites)
        {
            int f=x[0];
            int s=x[1];
            adj[s].push_back(f);
        }

        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                if(dfs(adj,vis,path,i)==true)
                return false;
            }
        }

        return true;
    }
};
