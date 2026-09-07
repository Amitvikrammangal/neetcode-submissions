class Solution {
public:
    
    bool answer(vector<int>& nums, int i, int target,
               vector<vector<int>>& dp) 
    {
        if(target==0)
        return true;

        if(i>=nums.size())
        return false;

        if(dp[i][target]!=-1)
        return dp[i][target];

        bool take =false;

        if(nums[i]<=target)
        {
             take=answer(nums,i+1,target-nums[i],dp);
        }

          bool nottake=answer(nums,i+1,target,dp);

        return dp[i][target] = take || nottake;
    }
    bool canPartition(vector<int>& nums) {
       int total=0;
       for(auto num:nums)
       {
          total+=num;
       } 
       if(total%2!=0) 
       return false;

       int target=total/2;

       vector<vector<int>> dp(nums.size(),vector<int> (target+1,-1));

      return  answer(nums,0,target,dp);
    }
};
