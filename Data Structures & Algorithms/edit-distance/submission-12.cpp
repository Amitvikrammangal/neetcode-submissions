class Solution {
public:
    int solve(string s1,string s2,int i,int j,vector<vector<int>> &dp)
    {
        int ans;
        if(i==s1.length())
        return s2.length()-j;

        if(j==s2.length())
        return s1.length()-i;

        if(dp[i][j]!=-1)
         return dp[i][j];

        if(s1[i]==s2[j])
        return dp[i][j]=solve(s1,s2,i+1,j+1,dp);

        else
        {
            // increment
            int increment=1+solve(s1,s2,i,j+1,dp);

            // decrement
            int decrement=1+solve(s1,s2,i+1,j,dp);

            // replace
            int replace=1+solve(s1,s2,i+1,j+1,dp);


             dp[i][j]= min(increment,min(decrement,replace));
        }

        return dp[i][j];


    }
    int minDistance(string s1, string s2) {
        vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        return solve(s1,s2,0,0,dp);
    }
};
