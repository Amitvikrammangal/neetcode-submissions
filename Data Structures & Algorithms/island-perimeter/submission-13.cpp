class Solution {
public:
    void answer(vector<vector<int>>& grid,int r,int c,int &output,vector<vector<int>>& vis)
    {
        if(r<0 || r>=grid.size() ||c<0 || c>=grid[0].size())
        {
            output++;
            return ;
        }

        if(grid[r][c]==0)
        {
            output++;
            return;
        }

        if(vis[r][c]==1) 
        {
           return;
        }

        vis[r][c]=1;
        answer(grid,r-1,c,output,vis);
        answer(grid,r+1,c,output,vis);
        answer(grid,r,c-1,output,vis);
        answer(grid,r,c+1,output,vis);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int output=0;
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 if(grid[i][j]==1)
                 {
                    answer(grid,i,j,output,vis);
                 return output;
                 }
            }
        }
       
    }
};