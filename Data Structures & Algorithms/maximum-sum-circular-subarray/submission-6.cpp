class Solution {
public:
    int solve_max(vector<int> &nums)
    {
        int max_sum=INT_MIN;
        int curr_sum=0;

        for(int i=0;i<nums.size();i++)
        {
            curr_sum+=nums[i];
            max_sum=max(max_sum,curr_sum);
            if(curr_sum<0)
            {
                curr_sum=0;
            }
        }
        return max_sum;
    }

       int solve_min(vector<int> &nums)
    {
        int min_sum=INT_MAX;
        int curr_sum=0;

        for(int i=0;i<nums.size();i++)
        {
            curr_sum+=nums[i];
            min_sum=min(min_sum,curr_sum);
            if(curr_sum>0)
            {
                curr_sum=0;
            }
        }
        return min_sum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0;
        for(auto x:nums)
        {
            sum+=x;
        }
        int max_sum=solve_max(nums);
        int min_sum=solve_min(nums);
        if(max_sum>0)
        return max(max_sum,sum-min_sum);

        return max_sum;
    }
};