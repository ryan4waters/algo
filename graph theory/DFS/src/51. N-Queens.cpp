class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>tmp(n, string(n,'.'));
        int row = 0;
        dfs(n, res, tmp, row);
        return res;
    }
    void dfs(const int& n, vector<vector<string>>& res, vector<string>& tmp, int row) {
        if (row == n) {
            res.emplace_back(tmp);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (!isQvalid(tmp, row, i, n)) continue;
            tmp[row][i] = 'Q';
            dfs(n, res, tmp, row + 1);
            tmp[row][i] = '.';
        }
    }
    bool isQvalid(const vector<string>& tmp, const int& row, const int& col, const int& n) {
        for (int i = 0; i < n; ++i) {
            if (tmp[i][col] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; (i >= 0) && (j >= 0); --i, --j) {
            if (tmp[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; (i >= 0) && (j < n); --i, ++j) {
            if (tmp[i][j] == 'Q') return false;
        }
        return true;
    }
};