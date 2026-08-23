class Solution {
public:

    void answer(vector<vector<int>>& grid,
                int r,
                int c,
                vector<vector<int>>& vis,
                int &output)
    {
        // Outside grid
        if(r < 0 || r >= grid.size() ||
           c < 0 || c >= grid[0].size())
        {
            return;
        }

        // Water
        if(grid[r][c] == 0)
        {
            return;
        }

        // Already visited
        if(vis[r][c] == 1)
        {
            return;
        }

        // Mark visited
        vis[r][c] = 1;

        // Count this land cell
        output++;

        // DFS 4 directions
        answer(grid, r-1, c, vis, output);
        answer(grid, r+1, c, vis, output);
        answer(grid, r, c-1, vis, output);
        answer(grid, r, c+1, vis, output);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        if(grid.empty())
            return 0;

        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1 && vis[i][j] == 0)
                {
                    int output = 0;

                    answer(grid, i, j, vis, output);

                    ans = max(ans, output);
                }
            }
        }

        return ans;
    }
};