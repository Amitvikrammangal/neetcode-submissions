class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> dist(n+1,INT_MAX);

        for(auto edge:times)
        {
            int source=edge[0];
            int destination=edge[1];
            int time=edge[2];

            adj[source].push_back({destination,time});
        }
        

           priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int, int>>
             > pq;

            pq.push({0,k}); 
            dist[k]=0;

            while(!pq.empty())
            {
                auto it=pq.top();
                pq.pop();
                int oldtime=it.first;
                int node=it.second;

                for(auto neib:adj[node])
                {
                    int dest=neib.first;
                    int time=neib.second;


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
