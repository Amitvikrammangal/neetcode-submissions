class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        dp[1]=1;

        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                int p1=j*(i-j);
                int p2=j*dp[i-j];

                dp[i]=max(dp[i],max(p1,p2));
            }
        }
        return dp[n];
    }
};