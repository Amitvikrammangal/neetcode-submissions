class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        int fresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                 q.push({i,j});


                if(grid[i][j] == 1)
                    fresh++;
            }
        }

         int dr[]={-1,+1,0,0};
         int dc[]={0,0,-1,+1};

        while(q.empty()==0&& fresh>0)
        {
            int size=q.size();

             for(int j = 0; j < size; j++)
            {
            auto [r,c]=q.front();
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr<0 || nr>=n ||nc<0||nc>=m)
                  continue;

               

                if(grid[nr][nc] == 0 || grid[nr][nc] == 2)
                {
                    continue;
                }

                grid[nr][nc]=2;
                fresh--;
                q.push({nr,nc});

              }
            }
            ans++;
        }
        if(fresh>0) return -1;

        else
        return ans;
    }
};
