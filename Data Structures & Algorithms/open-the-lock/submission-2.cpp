class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead;
        int steps=0;

        for(auto x:deadends)
        {
            dead.insert(x);
        }

        if(dead.count("0000"))
        return -1;

        queue<string> q;

        unordered_set<string> visited;
        q.push("0000");
        while(q.empty()==0)
        {
            int size=q.size();

           while(size>0)
           {
             string curr=q.front();
             q.pop();

             if(curr == target)
                 return steps;


             for(int i=0;i<4;i++)
             {
                string next=curr;

                next[i]++;
                if(next[i]>'9')
                {
                    next[i]='0';
                }
                if(!dead.count(next) && !visited.count(next))
                {
                    q.push(next);
                    visited.insert(next);
                }
                
                 next=curr;
                 next[i]--;
                if(next[i]<'0')
                {
                    next[i]='9';
                }
                if(!dead.count(next) && !visited.count(next))
                {
                    q.push(next);
                    visited.insert(next);
                }
             }
             size--;
           }
           steps++;

        }
        return -1;
        
    }
};