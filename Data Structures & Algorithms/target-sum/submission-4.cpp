class Solution {
public:
    int solve(vector<int> &nums,int target,int i,int sum,unordered_map<string,int> &mp){
        if(i==nums.size())
        {
            if(target==sum)
            return 1;

            else 
            return 0;
        }
        string key=to_string(i)+"_"+to_string(sum);
        if(mp.find(key)!=mp.end())
        {
            return mp[key];
        }

        int takepositive=solve(nums,target,i+1,sum+nums[i],mp);
        int takenegative=solve(nums,target,i+1,sum-nums[i],mp);

        return mp[key]=takepositive+takenegative;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<string,int> mp;
       return solve(nums,target,0,0,mp);
    }
};
