class Solution {
public:
    bool answer(vector<vector<int>>& prerequisites,int idx,vector<bool> &vis,vector<bool> &recpath)
    {
        vis[idx]=1;
        recpath[idx]=1;

        for(int i=0;i<prerequisites.size();i++)
        {
             int v=prerequisites[i][0];
             int u=prerequisites[i][1];

             if(u==idx)
             {
                if(!vis[v])
                {
                    if(answer(prerequisites,v,vis,recpath)==1)
                    return true;
                }
                else if(recpath[v]==1)
                 return true;
             }
        }
        
             recpath[idx]=0;
             return false;
        
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<bool> vis(n,0);
        vector<bool> recpath(n,0);

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
               if(answer(prerequisites,i,vis,recpath)==1)
                  return false;
            }
        }
        return true;
    }
};
