class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>tmp;
        deque<bool>used(nums.size(), false);
        dfs(nums, res, tmp, used);
        return res;
    }
    void dfs(const vector<int>& nums, vector<vector<int>>& res, vector<int>& tmp, deque<bool>& used) {
        if (tmp.size() == nums.size()) {
            for (const auto& c:res) {
                if (c == tmp) return;
            }
            res.emplace_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            tmp.emplace_back(nums[i]);
            used[i] = true;
            dfs(nums, res, tmp, used);
            used[i] = false;
            tmp.pop_back();
        }
    }
};