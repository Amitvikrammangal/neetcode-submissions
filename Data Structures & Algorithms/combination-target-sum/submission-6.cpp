class Solution {
public:
    void answer(vector<int>& nums,vector<int>& temp,int i,vector<vector<int>>& ans,int target)
    {
        if(target==0) 
        {
            ans.push_back(temp);
            return;
        }

        if(target<0 || i==nums.size())
          return;

        temp.push_back(nums[i]);
        answer(nums,temp,i,ans,target-nums[i]);
        //answer(nums,temp,i+1,ans,target-nums[i]);
        temp.pop_back();
        answer(nums,temp,i+1,ans,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        answer(nums,temp,0,ans,target);
        return ans;
    }
};
