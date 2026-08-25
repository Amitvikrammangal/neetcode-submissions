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


    void topo(vector<vector<int>>& prerequisites,stack<int>& s,int idx,vector<int>& viss)
    {
        viss[idx]=1;
        for(int i=0;i<prerequisites.size();i++)
        {
             int v=prerequisites[i][0];
             int u=prerequisites[i][1];

             if(u==idx)  
             {
                if(!viss[v])
                {
                    topo(prerequisites,s,v,viss);
                }
             }
        }
        s.push(idx);
        
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites)  {
        vector<bool> vis(n,0);
        vector<int> viss(n,0);
        vector<bool> recpath(n,0);
        stack<int> s;
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
               if(answer(prerequisites,i,vis,recpath)==1)
                  return ans;
            }
        }

         for(int i=0;i<n;i++)
        {
            if(!viss[i])
            {
               topo(prerequisites,s,i,viss);
            }
        }
      while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};