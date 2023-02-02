class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>tmp;
        int idx = 1;
        dfs(n, k, res, tmp, idx);
        return res;
    }
    void dfs(const int& n, const int& k, vector<vector<int>>& res, vector<int>& tmp, int idx) {
        if (tmp.size() == k) {
            res.emplace_back(tmp);
            return;
        }
        for (int i = idx;i <= n - (k - tmp.size()) + 1; ++i) {
            tmp.emplace_back(i);
            dfs(n, k, res, tmp, i + 1);
            tmp.pop_back();
        }
    }
};