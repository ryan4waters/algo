class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '0') continue;
                ++res;
                dfs(grid, i, j);
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& grid, const int& row, const int& col) {
        if ((row < 0) || (row >= grid.size()) || (col < 0) || (col >= grid[0].size())) return;
        if (grid[row][col] == '0') return;
        grid[row][col] = '0';
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
    }
};