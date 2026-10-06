class Solution {
public:
    int solution(vector<int>& piles, int i, int m, int person,
                 vector<vector<vector<int>>>& dp) {

        int n = piles.size();

        if (i >= n)
            return 0;

        if (dp[i][person][m] != -1)
            return dp[i][person][m];

        int result;

        if (person == 0)
            result = 0;
        else
            result = INT_MAX;

        int sum = 0;

        for (int x = 1; x <= min(2 * m, n - i); x++) {

            sum += piles[i + x - 1];

            if (person == 0) {

                result = max(result,(sum + solution(piles,i + x,max(m, x),1,dp)));

            } else {

                result = min(result,solution(piles,i + x,max(m, x),0,dp));
            }
        }

        return dp[i][person][m] = result;
    }

    int stoneGameII(vector<int>& piles) {

        int n = piles.size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(n + 1, -1)));

        return solution(piles, 0, 1, 0, dp);
    }
};