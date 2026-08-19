class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> q;
        string ans="";
        for(auto temp:s)
        {
            mp[temp]++;
        } 

        for(auto temp:mp)
        {
             q.push({temp.second,temp.first});
        }

        while(q.size()>=2)
        {
            auto first=q.top();
            q.pop();
            auto second=q.top();
            q.pop();
            ans.push_back(first.second);
            ans.push_back(second.second);
            first.first--;
            second.first--;
            if(first.first>0)
            q.push(first);

            if(second.first>0)
            q.push(second);
        }

            if(!q.empty())
        {
            auto last = q.top();

            if(last.first > 1)
                return "";

            ans.push_back(last.second);
        }

        return ans;
        
    }
};