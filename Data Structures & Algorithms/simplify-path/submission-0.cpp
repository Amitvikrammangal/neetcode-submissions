class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string  ans;
        int i=0;
       while(i<path.size())
       {
         if(path[i]=='/')
         {
            i++;
             continue;
         }
            string folder = "";
            while(i<path.size() && path[i]!='/')
            {
                folder+=path[i];
                i++;
            }

            if(folder==".") 
              continue;

            else if(folder=="..")
            {
                if(!st.empty())
                    st.pop();
            }

             else
             {
                 st.push(folder);
             } 
       }
     
        if(st.empty()==1) return ans="/";
         while(!st.empty())
         {
             ans="/"+st.top()+ans;
             st.pop();
         }
         return ans;

      
    }
};