class Solution {
public:
    int solve(int i,int j,int n,int m,string t1,string t2,vector<vector<int>> &dp)
    {
        if(i==n || j==m)
        return 0;

        if(t1[i]==t2[j])
        return 1+solve(i+1,j+1,n,m,t1,t2,dp);

        if(dp[i][j]!=-1)
        return dp[i][j];

        else 
          dp[i][j]= max(solve(i+1,j,n,m,t1,t2,dp),solve(i,j+1,n,m,t1,t2,dp));

        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,n,m,text1,text2,dp);
    }
};
