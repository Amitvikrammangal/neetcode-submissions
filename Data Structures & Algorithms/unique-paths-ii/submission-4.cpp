class Solution {
public:
    int solve(vector<vector<int>> grid,int m,int n,int i,int j,vector<vector<int>> &dp)
    {
        if(i<0 || i>=m || j<0 || j>=n  || grid[i][j]==1)
          return 0;

         if(dp[i][j]!=-1)
         return dp[i][j];

         if(i==m-1 && j==n-1)
         return 1;

         return dp[i][j]=solve(grid,m,n,i+1,j,dp)+solve(grid,m,n,i,j+1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

         vector<vector<int>> dp(m,vector<int> (n,-1));
        return  solve(grid,m,n,0,0,dp);
    }
};