class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        vector<int>tmp;
        int idx = 0;
        dfs(nums, tmp, res, idx);
        return res;
    }
    void dfs(vector<int>& nums, vector<int>& tmp, vector<vector<int>>& res, int idx) {
        unordered_set<int>s;
        res.emplace_back(tmp);
        if (idx > nums.size() - 1) {
            return;
        }
        for (int i = idx; i < nums.size(); ++i) {
            if (s.find(nums[i]) != s.end()) {
                continue;
            }
            tmp.emplace_back(nums[i]);
            s.insert(nums[i]);
            dfs(nums, tmp, res, i + 1);
            tmp.pop_back();
        }
    }
};