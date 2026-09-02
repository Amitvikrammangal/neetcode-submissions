class Solution {
public:
    int distance(vector<vector<int>>& points,int p1,int p2)
    {
        return abs(points[p1][0]-points[p2][0])+abs(points[p1][1]-points[p2][1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
          int n = points.size();

        // {cost, point}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<bool> vis(n, false);
        int cost=0;

        pq.push({0,0});
        while(!pq.empty())
        {
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if(vis[node]) continue;

            vis[node]=true;
            cost=cost+wt;

            for(int i=0;i<n;i++)
            {
                if(!vis[i])
                {
                    int edgedis=distance(points,node,i);
                    pq.push({edgedis,i});
                }
            }
        }
        return cost;
    }
};
