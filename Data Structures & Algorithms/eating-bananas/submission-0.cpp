class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e= *max_element(piles.begin(),piles.end());
        while(s<=e)
        {
             int mid=(s+e)/2;
             int hrs=0;
             for(auto pile:piles)
             {
                 hrs+=(pile+mid-1)/mid;  // ceil formula
             }
              
            if(hrs<=h)
            {
               e=mid-1;
            }
            else 
            {
                 s=mid+1;
            }
        }
        return s;
    }
};
