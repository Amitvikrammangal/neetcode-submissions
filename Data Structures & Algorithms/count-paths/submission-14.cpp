class Solution {
public:
    int solve(vector<vector<int>> &dp,int r,int c)
    {
        if(r==0 && c==0)
        {
            return 1;
        }

        if(r<0 || c<0)
        return 0;

        if(dp[r][c]!=-1)
          return dp[r][c];

        return dp[r][c]=solve(dp,r-1,c)+solve(dp,r,c-1);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solve(dp,m-1,n-1);
    }
};
