class Solution {
public:
    int solve(vector<int> prices,int buy,int i,vector<vector<int>> &dp)
    {
        if(i>=prices.size())
        return 0;

        if(dp[i][buy]!=-1)
        return dp[i][buy];

        if(buy==1)
        {
            int take=solve(prices,0,i+1,dp)-prices[i];
            int nottake=solve(prices,1,i+1,dp);

            return dp[i][buy]=max(take,nottake);
        }
      else
        {
            int sell=solve(prices,1,i+2,dp)+prices[i];
            int notsell=solve(prices,0,i+1,dp);

            return dp[i][buy]=max(sell,notsell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,1,0,dp);
    }
};
