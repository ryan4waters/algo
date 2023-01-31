class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>path;
        deque<bool>used(nums.size(), false);
        dfs(nums, path, used, res);
        return res;
    }
    void dfs(const vector<int>&nums, vector<int>&path, deque<bool>&used, vector<vector<int>>&res) {
        if (path.size() == nums.size()) {
            res.emplace_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            path.emplace_back(nums[i]);
            used[i] = true;
            dfs(nums, path, used, res);
            used[i] = false;
            path.pop_back();
        }
    }
};