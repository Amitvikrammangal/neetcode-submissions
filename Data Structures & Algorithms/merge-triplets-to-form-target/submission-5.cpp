class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> maxvalues(3,0);

        for(auto triplet:triplets)
        {
            if(triplet[0]<=target[0] && triplet[1]<=target[1] && triplet[2]<=target[2])
            {
                maxvalues[0]=max(maxvalues[0],triplet[0]);
                maxvalues[1]=max(maxvalues[1],triplet[1]);
                maxvalues[2]=max(maxvalues[2],triplet[2]);
            }
        }
        return maxvalues[0]==target[0] && maxvalues[1]==target[1] && maxvalues[2]==target[2];
    }
};
