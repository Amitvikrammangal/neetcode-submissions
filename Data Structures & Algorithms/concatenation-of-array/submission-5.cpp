class Solution {
public:
    vector<int> getConcatenation(vector<int>& arr) {
       int size=arr.size(); //4
      vector<int> ans(size * 2); //8
    for(int i=0;i<size;i++)
    {
        ans[i]=arr[i];
        ans[i+size]=arr[i];
    }
    
    return ans;
    }
};
