class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>tmp;
        int idx = 0;
        dfs(s, res, tmp, idx);
        return res;
    }
    void dfs(const string& s, vector<vector<string>>& res, vector<string>& tmp, int idx) {
        if (idx == s.size()) {
            res.emplace_back(tmp);
            return;
        }
        for (int i = idx; i < s.size(); ++i) {
            if (!isgoback(s, idx, i)) continue;
            else {
                string str = s.substr(idx, i - idx + 1);
                tmp.emplace_back(str);
                dfs(s, res, tmp, i + 1);
                tmp.pop_back();    
            }
        }
    }
    bool isgoback(const string& s, const int& l, const int& r) {
        for (int i = l, j = r; i < j; ++i, --j) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
};