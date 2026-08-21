class Solution {
public:
    void answer(vector<string> &ans,string& temp,int open,int close,int n)
    {
        if(temp.size()==2*n)
        {
            ans.push_back(temp);
        }
        
        if(open<n)
        {
            temp.push_back('(');
            answer(ans,temp,open+1,close,n);
            temp.pop_back();
        }

        if(close<open)
        {
            temp.push_back(')');
            answer(ans,temp,open,close+1,n);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp="";
        vector<string> ans;
        answer( ans, temp,0,0,n);
        return ans;
    }
};
