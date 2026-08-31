class Solution {
public:
     double dfs(string curr,string target,double value,unordered_map<string, vector<pair<string,double>>>& graph,
                                                                                    unordered_set<string>& visited)
               {
                 if(curr==target)
                  return value;

                  visited.insert(curr);

                  for(auto neib:graph[curr])
                  {
                       string next=neib.first;
                       double weight=neib.second;

                       if(visited.count(next)) //next element  visited
                        continue;

                       
                         double ans= dfs(next,target,weight*value,graph,visited);

                         if(ans!=-1)
                         return ans;
                  }
                  return -1;
               }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string,vector<pair<string,double>>> graph;

        for(int i=0;i<equations.size();i++)
        {
            string s1=equations[i][0];
            string s2=equations[i][1];
            double value=values[i];

            graph[s1].push_back({s2,value});
            graph[s2].push_back({s1,1.0/value});
        }

        vector<double> ans;

        for(auto query:queries)
        {
            string start=query[0];
            string target=query[1];

            if(!graph.count(start) || !graph.count(target))
            {
                ans.push_back(-1.0);
                continue;
            }

            unordered_set<string> visited;
            double result=dfs(start,target,1.0,graph,visited);
            ans.push_back(result);
        }
        return ans;

    }
};