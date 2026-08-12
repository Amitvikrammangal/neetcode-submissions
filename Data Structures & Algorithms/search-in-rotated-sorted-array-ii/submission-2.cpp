class Solution {
public:
    bool search(vector<int>& arr, int target) {
         int s=0;
        int e=arr.size()-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(arr[mid]==target)
            {
                 return true;
            }
            else if(arr[s]==arr[mid] && arr[mid]==arr[e])
            {
                 s++;
                 e--;
            }
             else if(arr[s]<=arr[mid]) // left part sorted
               {
                  if(arr[s]<=target && target<=arr[mid])
                  {
                        e=mid-1;
                  }
                  else
                  {
                     s=mid+1;
                  }
               }
             else  if(arr[mid]<=arr[e])// right part sorted
             {
                if(arr[mid]<=target &&  target<=arr[e])
                {
                    s=mid+1;
                }
                else 
                {
                     e=mid-1;
                }
             }
        }
        return false;
    }
    
};