class Solution {
public:
    bool  check(string s)
    {
        string temp=s;
         reverse(temp.begin(),temp.end());
        if(s==temp)
        return true;

        else
        return false;
    }
    void answer(string s,vector<vector<string>> &ans,vector<string>& temp)
    {
        if(s.size()==0)
        { 
            ans.push_back(temp);
        }

      for(int i=0;i<s.size();i++)
      {
          string part=s.substr(0,i+1);

          if(check(part)==1)
          {
            temp.push_back(part);
            answer(s.substr(i+1),ans,temp);
            temp.pop_back();
          }
      }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        answer(s,ans,temp);
        return ans; 
    }
};
