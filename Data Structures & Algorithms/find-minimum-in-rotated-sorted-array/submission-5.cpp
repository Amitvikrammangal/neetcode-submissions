class Solution {
public:
    int findMin(vector<int> &arr) {
        int s=0;
        int e=arr.size()-1;
        int m;
        while(s<e)
        {
            int mid=(s+e)/2;

             if(arr[mid]>arr[e])
               s=mid+1;
             else 
             e=mid;


             m=mid;
        }
         m=(s+e)/2;
        return arr[m];
    }
};
