class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int mid=0;
        int l=0,result=n;
        int r=n-1;
        sort(begin(nums),end(nums));
        while(l<=r)
        {
            int mid=l+(r-l)/2;

            if(nums[mid]>mid)
            {
                result=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return result;
    }
};
