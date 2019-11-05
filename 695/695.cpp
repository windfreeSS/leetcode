class Solution {
    vector<pair<int, int>> offset_arr;
    int m;
    int n;
public:
    void dfs(vector<vector<int>>&grid, int row, int col, int &sum )
    {
        ++sum;
        for (int i = 0; i < 4; ++i)
        {
            int next_r = row + offset_arr[i].first;
            int next_c = col + offset_arr[i].second;
            if (next_r < 0 || next_r >= m)
            {
                continue;
            }
            if (next_c < 0 || next_c >= n)
            {
                continue;
            }
            if (grid[next_r][next_c] == 0)
            {
                continue;
            }
            grid[next_r][next_c] = 0;
            
            dfs(grid, next_r, next_c, sum);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> cp = grid;
        offset_arr = {{ -1, 0}, {0, 1}, {1, 0}, {0, -1}};

        int max_area = 0;
        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                if (cp[r][c] == 0)
                {
                    continue;
                }
                cp[r][c] = 0;
                int sum = 0;
                dfs(cp, r, c, sum);
                if (sum > max_area)
                {
                    max_area = sum;
                }
            }
        }
        return max_area;

    }
};
