class Solution {
public:

    bool searchans(vector<vector<int>>& matrix,int target,int midrow)
    { 
        int n=matrix[0].size();
        int s=0;
        int e=n-1;
        while(s<=e)
        {
             int mid=(s+e)/2;
             if(target==matrix[midrow][mid]) 
             {
                 return true;
             }
             else if(target>matrix[midrow][mid])
             {
                 s=mid+1;
             }
             else
             {
                e=mid-1;
             }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int sr=0;
        int er=m-1;
        while(sr<=er)
        {
             int midrow=(sr+er)/2;
             if(matrix[midrow][0]<=target && matrix[midrow][n-1]>=target)
             {
                if(searchans(matrix,target,midrow)) return true;
                else return false;
             }
             else if(matrix[midrow][0]>target)
             {
                 er=midrow-1;
             }
             else
             {
                 sr=midrow+1;
             }
        }
        return false;
    }
};
