class Solution {
public:
    vector<vector<int>>res;
    vector<int>tmp;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
        int target = n;
        dfs(nums, target, k, 0);
        return res;
    }
    void dfs(const vector<int>& nums, const int& target, const int& k, int idx) {
         if ((tmp.size() == k) && (accumulate(tmp.begin(), tmp.end(), 0) == target)) {
            res.emplace_back(tmp);
            return;
        }
        if ((tmp.size() > k) || (accumulate(tmp.begin(), tmp.end(), 0) > target)) return;
        for (int i = idx; i < nums.size(); ++i) { // check before, cut right brunch
            tmp.emplace_back(nums[i]);
            dfs(nums, target, k, i + 1);
            tmp.pop_back();
        }
    }
};