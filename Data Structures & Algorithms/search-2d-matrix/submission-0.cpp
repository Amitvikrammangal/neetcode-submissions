class Solution {
public:

    bool searchans(vector<vector<int>>& matrix,int target,int mr)
    { 
        int n=matrix[0].size();
        int s=0;
        int e=n-1;
        while(s<=e)
        {
             int mid=(s+e)/2;
             if(target==matrix[mr][mid]) 
             {
                 return true;
             }
             else if(target>matrix[mr][mid])
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
             int mr=(sr+er)/2;
             if(matrix[mr][0]<=target && matrix[mr][n-1]>=target)
             {
                if(searchans(matrix,target,mr)) return true;
                else return false;
             }
             else if(matrix[mr][0]>target)
             {
                 er=mr-1;
             }
             else
             {
                 sr=mr+1;
             }
        }
        return false;
    }
};
