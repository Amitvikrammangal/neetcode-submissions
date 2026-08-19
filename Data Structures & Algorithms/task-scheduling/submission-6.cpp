class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> q;
        int time=0;
        for(auto temp:tasks)
        {
             mp[temp]++;
        }
        for(auto temp:mp)
        {
            q.push({temp.second,temp.first});
        }

        while(q.empty()==0)
        {
            vector<pair<int,char>> temp;

            for(int i=0;i<=n;i++)
            {
                if(!q.empty())
                {
                    auto current=q.top();
                    q.pop();


                    current.first--;
                    temp.push_back(current);

                    time++;
                }
                else
                {
                    if(!temp.empty() && !q.empty())
                     time++;
                }
            } 
        

        for(auto x:temp)
        {
            if(x.first>0)
            q.push(x);
        }

        if(!q.empty())
            {
                time += (n + 1 - temp.size());
            }
            
        }
        return time;
    }
};
