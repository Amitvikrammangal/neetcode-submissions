class Solution {
public:
    void answer(vector<int>& nums,vector<vector<int>>& ans,vector<int>& temp,int i)
    {
         if(i==nums.size())
         {
             ans.push_back(temp);
             return;
         } 

         temp.push_back(nums[i]);
         answer(nums,ans,temp,i+1);
         temp.pop_back();
         answer(nums,ans,temp,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        answer(nums,ans,temp,0);
        return ans;
    }
};
