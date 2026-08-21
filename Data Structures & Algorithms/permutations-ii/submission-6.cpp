class Solution {
public:
    void answer(vector<int>& nums,set<vector<int>>& ans,int i)
    {
        if(i==nums.size())
        {
            ans.insert(nums);
            return;
        }

    
        for(int j=i;j<nums.size();j++)
        {
             swap(nums[j],nums[i]);
             answer(nums,ans,i+1);
             swap(nums[j],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        vector<vector<int>> anss;
        answer(nums,ans,0);
        for(auto x:ans)
        {
            anss.push_back(x);
        }
        return anss;
    }
};