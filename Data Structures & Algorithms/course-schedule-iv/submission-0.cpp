class Solution {
    public:

        void dfs(int node, vector<vector<int>>& graph,
                     vector<bool>& vis) {

                             vis[node] = true;

                                     for (int next : graph[node]) {
                                                 if (!vis[next]) {
                                                                 dfs(next, graph, vis);
                                                                             }
                                                                                     }
                                                                                         }

                                                                                             vector<bool> checkIfPrerequisite(
                                                                                                     int numCourses,
                                                                                                             vector<vector<int>>& prerequisites,
                                                                                                                     vector<vector<int>>& queries) {

                                                                                                                             vector<vector<int>> graph(numCourses);

                                                                                                                                     // [a,b] means a -> b
                                                                                                                                             for (auto &p : prerequisites) {
                                                                                                                                                         int a = p[0];
                                                                                                                                                                     int b = p[1];

                                                                                                                                                                                 graph[a].push_back(b);
                                                                                                                                                                                         }

                                                                                                                                                                                                 vector<vector<bool>> reach(
                                                                                                                                                                                                             numCourses,
                                                                                                                                                                                                                         vector<bool>(numCourses, false)
                                                                                                                                                                                                                                 );

                                                                                                                                                                                                                                         // DFS from every course
                                                                                                                                                                                                                                                 for (int i = 0; i < numCourses; i++) {

                                                                                                                                                                                                                                                             vector<bool> vis(numCourses, false);

                                                                                                                                                                                                                                                                         dfs(i, graph, vis);

                                                                                                                                                                                                                                                                                     for (int j = 0; j < numCourses; j++) {
                                                                                                                                                                                                                                                                                                     if (vis[j]) {
                                                                                                                                                                                                                                                                                                                         reach[i][j] = true;
                                                                                                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                                                                                                             }

                                                                                                                                                                                                                                                                                                                                                                     vector<bool> answer;

                                                                                                                                                                                                                                                                                                                                                                             for (auto &q : queries) {
                                                                                                                                                                                                                                                                                                                                                                                         int u = q[0];
                                                                                                                                                                                                                                                                                                                                                                                                     int v = q[1];

                                                                                                                                                                                                                                                                                                                                                                                                                 answer.push_back(reach[u][v]);
                                                                                                                                                                                                                                                                                                                                                                                                                         }

                                                                                                                                                                                                                                                                                                                                                                                                                                 return answer;
                                                                                                                                                                                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                                                                                                                                                                                     };
