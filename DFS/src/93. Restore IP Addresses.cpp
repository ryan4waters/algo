class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>res;
        if (s.size() > 12) return res;
        int idx = 0;
        int pointnum = 0;
        dfs(s, res, pointnum, idx);
        return res;
    }
    void dfs(string& s, vector<string>& res, int pointnum, int idx)
    {
        if (pointnum == 3) {
            if (isvalid(s, idx, s.size() - 1)) {
                res.emplace_back(s);
            }
            return;
        }
        for (int i = idx; i <s.size(); ++i) {
            if (!isvalid(s, idx, i)) break;
            s.insert(s.begin() + i + 1, '.');
            ++pointnum;
            dfs(s, res, pointnum, i + 2);
            --pointnum;
            s.erase(s.begin() + i + 1);
        }
    }
    bool isvalid(const string& s, const int& l, const int& r) {
        if (l > r) return false;
        if ((s[l] == '0') && (r != l)) return false;
        int sum = 0;
        for (int j = l; j <= r; ++j) {
            if (!isdigit(s[j])) return false;
            sum = sum * 10 + (s[j] - '0');
        }
        if (sum > 255) return false;
        return true;
    }
};