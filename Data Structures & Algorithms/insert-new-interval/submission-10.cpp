class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newinterval) {
        int n=interval.size();
       vector<vector<int>> ans; 
       int i=0;
        while(i<n && interval[i][1]<newinterval[0])
        {
            ans.push_back(interval[i]);
            i+=1;
        }

        while(i<n && interval[i][0]<=newinterval[1])
        {
            newinterval[0]=min(interval[i][0],newinterval[0]);
            newinterval[1]=max(interval[i][1],newinterval[1]);
             i+=1;
        }
        ans.push_back(newinterval);

        while(i<n)
        {
            ans.push_back(interval[i]);
             i+=1;
        }
        return ans;
    }
};
