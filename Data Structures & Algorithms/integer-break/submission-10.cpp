class Solution {
public:
    int solve(vector<int> &dp,int n)
    {
        if(n==1)
        return 1;

        if(dp[n]!=-1)
          return dp[n];

        int ans=0;
        for(int i=1;i<n;i++)
        {
            int p1=i*(n-i);
            int p2=i*solve(dp,n-i);
            ans=max(ans,max(p1,p2));
        }
        return dp[n]=ans;
        
    }
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
         return solve(dp,n);
         
    }
};