class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>tmp;
        int idx = 0;
        dfs(candidates, target, tmp, res, idx);
        return res;
    }
    void dfs(const vector<int>& candidates, const int& target, vector<int>& tmp, vector<vector<int>>& res, int idx) {
        if (accumulate(tmp.begin(), tmp.end(), 0) > target) return;
        if (accumulate(tmp.begin(), tmp.end(), 0) == target) {
            res.emplace_back(tmp);
            return;
        }
        for (int i = idx; i < candidates.size(); ++i) {
            tmp.emplace_back(candidates[i]);
            dfs(candidates, target, tmp, res, i);
            tmp.pop_back();
        }
    }
};