class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> score(n+1,0);

        for(auto x:trust)
        {
            score[x[0]]--;
            score[x[1]]++;
        }

        for(int i=0;i<n+1;i++)
        {
            if(score[i]==n-1)
            return i;
        }
        return -1;
    }
};