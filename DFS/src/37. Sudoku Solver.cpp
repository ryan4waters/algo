class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }
    bool dfs(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') continue;
                for (char val = '1'; val <= '9'; ++val) {
                    if (isvalid(board, i, j, val)) {
                        board[i][j] = val;
                        if (dfs(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    bool isvalid(const vector<vector<char>>& board, const int& row, const int&col, onst char& val) {
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == val) return false;
        }
        for (int j = 0; j < 9; ++j) {
            if (board[j][col] == val) return false;
        }
        int startrow = row / 3 * 3;
        int startcol = col / 3 * 3;
        for (int r = startrow; r < startrow + 3; ++r) {
            for (int c = startcol; c < startcol + 3; ++c) {
                if (board[r][c] == val) return false;
            }
        }
        return true;
    }
};