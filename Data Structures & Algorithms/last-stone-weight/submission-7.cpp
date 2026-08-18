class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        int i=0;
        while(i<stones.size())
        {
             q.push(stones[i]);
             i++;
        }

        while(q.size()>1)
        {
             int x=q.top();
             q.pop();
             int y=q.top();
             q.pop();
             if(x>y)
             {
                 q.push(x-y);
             }
        }
        if(q.empty()==1) return 0;
        else 
        return q.top();

    }
};
