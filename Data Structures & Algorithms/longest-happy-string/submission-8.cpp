class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> q;
        string ans= "";
        if(a>0) q.push({a,'a'});
        if(b>0) q.push({b,'b'});
        if(c>0) q.push({c,'c'});
        

        while(!q.empty())
        {
            auto first=q.top();
            q.pop();

            if(ans.size()>=2 && ans[ans.size()-1]==first.second && ans[ans.size()-2]==first.second)
            {
                 if(q.empty()) break;

                 auto second=q.top();
                 q.pop();

                 ans.push_back(second.second);

                 second.first--;
                if(second.first>0) 
                  q.push(second);
                

                if(first.first>0)
                q.push(first);
            } 
            else
            {
                ans.push_back(first.second);
                first.first--;

                if(first.first > 0)
                    q.push(first);
            }
        }
        return ans;
    }
};