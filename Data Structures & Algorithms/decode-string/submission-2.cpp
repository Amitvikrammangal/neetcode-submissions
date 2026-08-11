class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
             if(s[i]!=']')
             {
                 st.push(s[i]);
             }
             else
             {
                string folder="";
                 while(st.top()!='[')
                 {
                     folder=st.top()+folder;
                     st.pop();
                   
                 }
                 st.pop();
                 string temp="";
                

                 string num = "";

                while(!st.empty() && isdigit(st.top()))
                {
                    num = st.top() + num;
                    st.pop();
                }

                int number = stoi(num);
                 
                for(int k = 0; k < number; k++)
                {
                    temp = folder+temp;
                }

                for(auto ch:temp)
                {
                    st.push(ch);
                }

             }
        }

        string ans="";
          while(st.empty()==0)
          {
             ans=st.top()+ans;
             st.pop();
          }

            return ans;
        }
    };
    
