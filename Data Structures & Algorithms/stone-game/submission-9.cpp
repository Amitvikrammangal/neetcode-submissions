class Solution {
public:
    int solve(vector<int>&  piles,int i,int j,vector<vector<int>> &dp)
    {
        if(i>j)
        return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];

        int takestart=piles[i]+min(solve(piles,i+2,j,dp),solve(piles,i+1,j-1,dp));
        int takeend=piles[j]+min(solve(piles,i,j-2,dp),solve(piles,i+1,j-1,dp));

        return dp[i][j]=max(takestart,takeend);

    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int sum=0;

       vector<vector<int>> dp(n,vector<int>(n,-1));
        
        for(auto x:piles)
        {
            sum+=x;
        }

        int alice=solve(piles,0,n-1,dp);

        if(alice>sum/2)
        return true;

        return false;
    }
};