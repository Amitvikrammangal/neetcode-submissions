class Solution {
public:
    int helper(vector<int> nums,int s,int e)
    {
         vector<int> dp(nums.size()); 
          dp[s]=nums[s];
          dp[s+1]=max(nums[s],nums[s+1]);
        for(int i=s+2;i<=e;i++)
        {
             dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[e];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        if(nums.size()==1) return nums[0];     
        return max(helper(nums,0,n-2),helper(nums,1,n-1));
    }
};
