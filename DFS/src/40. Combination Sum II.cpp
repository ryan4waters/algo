class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>res;
        vector<int>tmp;
        int idx = 0;
        dfs(candidates, target, res, tmp, idx);
        return res;
    }
    void dfs(const vector<int>& candidates, const int& target, vector<vector<int>>& res, vector<int>& tmp, int idx) {
        unordered_set<int>myset;
        if (accumulate(tmp.begin(), tmp.end(), 0) == target) {
            res.emplace_back(tmp);
            return;
        }
        for (int i = idx; (i < candidates.size()) && (accumulate(tmp.begin(), tmp.end(), candidates[i]) <= target); ++i) {
            if (myset.find(candidates[i]) != myset.end()) continue;
            tmp.emplace_back(candidates[i]);
            myset.insert(candidates[i]);
            dfs(candidates, target, res, tmp, i + 1);
            tmp.pop_back();
        }
    }
};