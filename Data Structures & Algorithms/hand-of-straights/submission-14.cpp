class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        for(auto hands:hand)
        {
            mp[hands]++;
        }

        if(hand.size() % groupSize !=0)
        return false;

        while(!mp.empty())
        {
            int curr=mp.begin()->first;
            for(int i=0;i<groupSize;i++)
            {
               { 
                  if(mp[curr+i]==0)
                  return false;
                }

                mp[curr+i]-=1;
                if(mp[curr+i]==0)
                mp.erase(curr+i);
            }

        }
        return true;
    }
};
