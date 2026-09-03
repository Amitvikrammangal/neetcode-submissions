class Solution {
public:
    int answer(vector<int> &dp,vector<int> cost,int i)
    {
        if(i==0 || i==1) return 0;

        if(dp[i]!=-1)
        return dp[i];

        return dp[i]=min(answer(dp,cost,i-1)+cost[i-1],answer(dp,cost,i-2)+cost[i-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);

        return answer(dp,cost,n);
    }
};
