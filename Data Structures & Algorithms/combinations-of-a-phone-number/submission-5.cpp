class Solution {
public:
    void answer(string digits,vector<string>& ans,int i, string &temp,unordered_map<char,string>mp)
    {
        if(i==digits.size())
        {
            ans.push_back(temp);
            return;
        }
        string letter=mp[digits[i]];

        for(int j=0;j<letter.size();j++)
        {
            temp.push_back(letter[j]);
            answer(digits,ans,i+1,temp,mp);
            temp.pop_back();
        }


    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp;
        vector<string> ans;
        string temp;
        if(digits.size()==0) return ans;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        answer(digits,ans,0,temp,mp);
        return ans;
    }
};
