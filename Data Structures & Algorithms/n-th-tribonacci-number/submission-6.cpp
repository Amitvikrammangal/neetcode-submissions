class Solution {
public:

      int answer(vector<int> &dp,int n)
    {
        if(n==0) return 0;

        else if(n==1 || n==2) return 1;

        if(dp[n]!=-1)
        return dp[n];

        return dp[n]=answer(dp,n-1)+answer(dp,n-2)+answer(dp,n-3);
    }
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);

        return answer(dp,n);

    }
};