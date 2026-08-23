class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                 q.push({i,j});
            }
        }

         int dr[]={-1,+1,0,0};
         int dc[]={0,0,-1,+1};

        while(q.empty()==0)
        {


            auto [r,c]=q.front();
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr<0 || nr>=n ||nc<0||nc>=m)
                  continue;

                if(grid[nr][nc]==-1)
                {
                    continue;
                }

                if(grid[nr][nc]!=2147483647)
                {
                    continue;
                }

                grid[nr][nc]=grid[r][c]+1;
                q.push({nr,nc});

            }
        }
    }
};
