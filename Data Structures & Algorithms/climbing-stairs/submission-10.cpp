class Solution {
public:
    int answer(vector<int> &dp,int n)
    {
        if(n<=2) return n;

        if(dp[n]!=-1) return dp[n];

        return dp[n]=answer(dp,n-1)+answer(dp,n-2);

    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return answer(dp,n);
    }
};
