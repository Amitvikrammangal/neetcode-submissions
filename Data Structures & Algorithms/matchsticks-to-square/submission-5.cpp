class Solution {
public:
    bool answer(vector<int>& nums, vector<int>& square,
           int idx, int target)
    {
        if(idx==nums.size())
        {
            return true;
        }

        for(int j=0;j<square.size();j++)
        {
            if(square[j]+nums[idx]>target)
              continue;

            square[j]+=nums[idx];
            if(answer(nums,square,idx+1,target)==1)
            {
                 return true;
            }

            square[j]-=nums[idx];
        }
        return false;
    }
    bool makesquare(vector<int>& nums) {
        int sum=0;
        for(auto x:nums)
        {
            sum+=x;
        }
         if(sum%4!=0) return false;

         int target=sum/4;

         //sort in decending order
         sort(nums.begin(), nums.end());
         reverse(nums.begin(), nums.end());

         vector<int> square(4,0);
         return answer(nums,square,0,target);
    }
};