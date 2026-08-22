class Solution {
public:
    bool answer(vector<int>& nums, vector<int>& bucket,
           int idx, int target)
    {
        if(idx==nums.size())
        {
            return true;
        }

        for(int j=0;j<bucket.size();j++)
        {
            if(bucket[j]+nums[idx]>target)
              continue;

            bucket[j]+=nums[idx];
            if(answer(nums,bucket,idx+1,target)==1)
            {
                 return true;
            }

            bucket[j]-=nums[idx];
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(auto x:nums)
        {
            sum+=x;
        }
         if(sum%k!=0) return false;

         int target=sum/k;
         sort(nums.rbegin(), nums.rend());

         vector<int> bucket(k,0);
         return answer(nums,bucket,0,target);
    }
};