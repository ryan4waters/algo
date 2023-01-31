class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int tmp  =0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) continue;
                tmp = dfs(grid, i, j);
                res = max(res, tmp);
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& grid, const int& row, const int& col) {
        if ((row < 0) || (col < 0) || (row >= grid.size()) || (col >= grid[0].size()) || (grid[row][col] == 0))
        return 0;
        grid[row][col] = 0;
        return dfs(grid,row,col + 1) +
        dfs(grid, row, col - 1) +
        dfs(grid, row + 1, col) +
        dfs(grid, row - 1, col) + 1;
    }
};