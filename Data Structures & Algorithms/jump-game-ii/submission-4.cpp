class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0;
        int r=0;
        int jumps=0;
        int n=nums.size();
        while(r<n-1)
        {
            int fartest=0;
            for(int i=l;i<=r;i++)
            {
                fartest=max(i+nums[i],fartest);
            }
              l=r+1;
              r=fartest;
              jumps+=1;
        }
        return jumps;
    }
};
