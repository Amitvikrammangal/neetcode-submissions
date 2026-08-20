class Solution {
public:
    void answer(vector<int>& nums,int k,vector<vector<int>>& ans,vector<int>& temp,int i)
    {

        if(temp.size()==k)
        {
            ans.push_back(temp);
            return;
        }

        if(i==nums.size()) return;


        temp.push_back(nums[i]);
        answer(nums,k,ans,temp,i+1);
        temp.pop_back();

        answer(nums,k,ans,temp,i+1);
    }
    vector<vector<int>> combine(int n, int k) {
         vector<int> nums;
         vector<int> temp;
         vector<vector<int>> ans;
          for(int i=1;i<=n;i++)
          {
             nums.push_back(i);
          }
          answer(nums,k,ans,temp,0);
          return ans;
    }
};