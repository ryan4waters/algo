class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>tmp;
        int idx = 0;
        dfs(nums, tmp, res, idx);
        return res;
    }
    void dfs(vector<int>& nums, vector<int>& tmp, vector<vector<int>>& res, int idx) {
        res.emplace_back(tmp);
        if (idx > nums.size() - 1) {
            return;
        }
        for (int i = idx; i < nums.size(); ++i) {
            tmp.emplace_back(nums[i]);
            dfs(nums, tmp, res, i + 1);
            tmp.pop_back();
        }
    }
};