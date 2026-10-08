class Solution {
public:
    int solve(string s, string t, int n, int m, vector<vector<int>>& dp)
    {
        if (m == 0)
            return dp[n][m]= 1;

        if (n == 0)
            return dp[n][m]= 0;

        if (dp[n][m] != -1)
            return dp[n][m];

        if (s[n-1] == t[m-1])
        {
            return dp[n][m] =
                solve(s, t, n-1, m-1, dp) +
                solve(s, t, n-1, m, dp);
        }
        else
        {
            return dp[n][m] =
                solve(s, t, n-1, m, dp);
        }

    }

    int numDistinct(string s, string t)
    {
        vector<vector<int>> dp(s.length()+1, vector<int>(t.length()+1, -1));

        return solve(s, t, s.length(), t.length(), dp);
    }
};