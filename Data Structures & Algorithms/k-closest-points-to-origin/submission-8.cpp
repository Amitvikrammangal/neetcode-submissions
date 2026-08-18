class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
        pair<int, vector<int>>,
        vector<pair<int, vector<int>>>,
        greater<pair<int, vector<int>>>
    > p;
        for(auto temp:points)
        {
             int first=temp[0];
             int second=temp[1];
        

            int distance=pow((first-0),2)+pow((second-0),2);

            p.push({distance,temp});

    }
      
      vector<vector<int>> ans;
      while(k>0)
      {
         ans.push_back(p.top().second);
         p.pop();
         k--;
      }
      return ans;
    }
};
