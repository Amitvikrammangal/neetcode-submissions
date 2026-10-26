class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals){ 
         sort(intervals.begin(), intervals.end());
            int n=intervals.size();
            int lastime=intervals[0][1];
            int count=0;


        for(int i=1;i<n;i++)
    {
        if(lastime>intervals[i][0])
        {
            count+=1;
            lastime=min(lastime,intervals[i][1]);
        }
        else
        {
            lastime=intervals[i][1];
        }
    }
    return count;
    }
};
