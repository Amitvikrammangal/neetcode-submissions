class Solution {
public:
    void answer(vector<vector<char>>& grid,int r,int c,vector<vector<int>>& vis)
    {
        if(r<0 || r>=grid.size() ||c<0 || c>=grid[0].size())
        {
           
            return ;
        }

        if(grid[r][c]=='0')
        {
            
            return;
        }

        if(vis[r][c]==1) 
        {
           return;
        }

        vis[r][c]=1;
        answer(grid,r-1,c,vis);
        answer(grid,r+1,c,vis);
        answer(grid,r,c-1,vis);
        answer(grid,r,c+1,vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
    return 0;
        int n=grid.size();
        int m=grid[0].size();
        int output=0;
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 if(grid[i][j]=='1' && vis[i][j]==0)
                 {
                    answer(grid,i,j,vis);
                     output++;
                 }
            }
        }
        return output;
    }
};
