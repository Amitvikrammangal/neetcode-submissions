class Solution {
public:
    int solve(vector<vector<int>> &matrix,int i,int j,vector<vector<int>> &memo)
    {
        if(i<0 || j<0 || i>=matrix.size() ||j>=matrix[0].size())
        return 0;

        if(memo[i][j]>0)
        return memo[i][j];

        int currentmax=1;

        if(i+1<matrix.size() && i>=0 && matrix[i+1][j]>matrix[i][j])
        {
            currentmax=max(currentmax,1+solve(matrix,i+1,j,memo));
        }
        if(i-1<matrix.size() && i>=0 && matrix[i-1][j]>matrix[i][j])
        {
            currentmax=max(currentmax,1+solve(matrix,i-1,j,memo));
        }
        if(j+1<matrix[0].size() && j>=0 && matrix[i][j+1]>matrix[i][j])
        {
            currentmax=max(currentmax,1+solve(matrix,i,j+1,memo));
        }
        if(j-1<matrix[0].size() && i>=0 && matrix[i][j-1]>matrix[i][j])
        {
            currentmax=max(currentmax,1+solve(matrix,i,j-1,memo));
        }
        return memo[i][j]=currentmax;


    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> memo(matrix.size(),vector<int>(matrix[0].size(),0));
        int maxx=-1;
        for(int i=0;i<=matrix.size();i++)
        {
            for(int j=0;j<=matrix[0].size();j++)
            {
                maxx=max(maxx,solve(matrix,i,j,memo));
            }
        }
        return maxx;

    }
};
