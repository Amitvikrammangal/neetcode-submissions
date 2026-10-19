class Solution {
public:
    void solve(string senate,vector<bool> &removed,char ch,int idx,int n)
    {
        while(true)
        {
            if(senate[idx]==ch && removed[idx]==false)
            {
                removed[idx]=true;
                break;
            }
            else
            idx=(idx+1)%n;
        }
    }
    string predictPartyVictory(string senate) {
        int n=senate.length();
        vector<bool> removed(n,false);

        int count_R=0;
        int count_D=0;

        for(auto x:senate)
        {
            if(x=='D')
            count_D++;
            else
            count_R++;
        }
    
        int idx=0;

        while(count_D>0 && count_R>0)
        {
            if(removed[idx]==false)
            {
                if(senate[idx]=='R')
                {
                    solve(senate,removed,'D',(idx+1)%n, n);
                    count_D-=1;
                }
                else
                {
                    solve(senate,removed,'R',(idx+1)%n, n);
                    count_R-=1;
                }
            }
            
                idx=(idx+1)%n;
           
        }

        if(count_R>0)
        return "Radiant";
        else
        return "Dire";
        
    }
};