class Solution {
public:
    int answer(int i,vector<int> &nums,vector<int> &dp)
    {
        if(dp[i]!=-1)
        return dp[i];

        dp[i]=1;

        for(int j=0;j<i;j++)
        {
            if(nums[j]<nums[i])
            {
                dp[i]=max(dp[i],answer(j,nums,dp)+1);
            }
        }
        return dp[i];
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        int ans=0;

        for(int i=0;i<nums.size();i++)
        {
            ans=max(ans,answer(i,nums,dp));
        }
        return ans;
    }
};
