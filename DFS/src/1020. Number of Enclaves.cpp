class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            dfs(grid, i, 0);
            dfs(grid, i, grid[0].size() - 1);
        }
        for (int j = 0; j < grid[0].size(); ++j) {
            dfs(grid, 0, j);
            dfs(grid, grid.size() - 1, j);
        }
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] == 0) continue;
                ++res;
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& grid, const int& r, const int& c) {
        if ((r < 0) || (c < 0) || (r >= grid.size()) || (c >= grid[0].size()) || (grid[r][c] == 0))
        return;
        grid[r][c] = 0;
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
    }
};