class Solution {
public:
    bool solve(string &s,string &p,int i,int j,vector<vector<int>> &dp)
    {
        if(i==s.length() && j==p.length())
        return true;

        else if(j==p.length())
        return false;
        
        if(dp[i][j]!=-1)
        return dp[i][j];

        bool firstmatch=false;

        if(i<s.length() && (s[i]==p[j] || p[j]=='.'))
         firstmatch=true;

        if(j<p.length() && p[j+1]=='*')
        {
            bool not_take=solve(s,p,i,j+2,dp);
            bool take=firstmatch && solve(s,p,i+1,j,dp);

            return dp[i][j]=take||not_take;
        }

        if(firstmatch)
        {
            return dp[i][j]=solve(s,p,i+1,j+1,dp);
        }

        return dp[i][j]=false;

    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length()+1,vector<int>(p.length()+1,-1));
        return solve(s,p,0,0,dp);
    }
};
