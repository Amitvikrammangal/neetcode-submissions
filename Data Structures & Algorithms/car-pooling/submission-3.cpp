class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > q;

        int currpassengers = 0;
        int i=0;
        while(i<trips.size())
        {
            int passengers=trips[i][0];
            int from=trips[i][1];
            int to=trips[i][2];
            
            while(!q.empty() && q.top().first<=from)
            {
                currpassengers-=q.top().second;
                q.pop();
            }

            currpassengers+=passengers;

            if(currpassengers>capacity)
            return false;

            q.push({to,passengers});
            i++;

        }
        return true;
    }
};