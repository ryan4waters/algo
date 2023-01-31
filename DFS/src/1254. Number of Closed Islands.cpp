class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            dfs(grid, i, 0);
            dfs(grid, i, grid[0].size() - 1);
        }
        for (int j = 0; j < grid[0].size(); ++j) {
            dfs(grid, 0, j);
            dfs(grid, grid.size() - 1, j);
        }
        int res = 0;
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] == 1) continue;
                ++res;
                dfs(grid, r, c);
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& grid, const int& row, const int& col) {
        if ((row < 0) || (col < 0) || (row >= grid.size()) || (col >= grid[0].size()) || (grid[row][col] == 1))
        return;
        grid[row][col] = 1;
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
    }
};