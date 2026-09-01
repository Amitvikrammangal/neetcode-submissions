class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();

        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));

           priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
             > pq;


            int rr[4]={-1,0,1,0};
            int cc[4]={0,-1,0,1};

            dist[0][0]=0;
            pq.push({0,{0,0}});
            while(!pq.empty())
            {
                auto it=pq.top();
                pq.pop();

                int distance=it.first;
                int r=it.second.first;
                int c=it.second.second;
                if(r==m-1  && c==n-1)
                return distance;

                for(int i=0;i<4;i++)
                {
                    int nr=r+rr[i];
                    int nc=c+cc[i];
                    
                    if(nr>=0 && nr<m && nc>=0 && nc<n)
                    {
                        int efforts=max(abs(heights[nr][nc]-heights[r][c]),distance);
                        if(dist[nr][nc]>efforts)
                        {
                            dist[nr][nc]=efforts;

                            pq.push({efforts,{nr,nc}});
                        }
                    }

            }       
    }
    }
};