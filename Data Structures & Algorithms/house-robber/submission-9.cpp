class Solution {
public:
    int answer(vector<int> nums,vector<int> &dp,int i)
    {
        if(i<0) return 0;

        if(dp[i]!=-1) return dp[i];

        return dp[i]=max(answer(nums,dp,i-1),answer(nums,dp,i-2)+nums[i]);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        answer(nums,dp,n-1);
        return dp[n-1];
    }
};
