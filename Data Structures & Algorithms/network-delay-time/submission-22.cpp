class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX);
         priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int, int>>
             > pq;

        vector<vector<pair<int,int>>> adj(n+1);
        for(auto edge:times)
        {
            int u=edge[0];
            int v=edge[1];
            int t=edge[2];
            adj[u].push_back({v,t});
        }
        dist[k]=0;

        pq.push({0,k});

        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int oldtime=it.first;
            int node=it.second;
            for(auto neib:adj[node])
            {
                int time=neib.second;
                int dest=neib.first;

                int newtime=time+oldtime;
                if(dist[dest]>newtime)
                {
                    dist[dest]=newtime;
                    pq.push({newtime,dest});
                }
            }
        }

        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INT_MAX)
            return -1;

            ans=max(ans,dist[i]);
        }
        return ans;
        
    }
};
