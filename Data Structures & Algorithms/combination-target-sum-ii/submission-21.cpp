class Solution {
public:

    void answer(vector<int>& nums, vector<int>& temp,
                int i, vector<vector<int>>& ans, int target)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }

        if(target < 0 || i == nums.size())
            return;

        for(int j=i;j<nums.size();j++)
        {
            if(j>i && nums[j]==nums[j-1])
            continue;

            if(nums[j]>target)
            break;

            temp.push_back(nums[j]);
            answer(nums, temp, j + 1, ans, target - nums[j]);
            temp.pop_back();
            
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());

        answer(nums, temp, 0, ans, target);

        return ans;

    
    }
};