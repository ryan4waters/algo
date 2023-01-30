class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        if (digits.empty()) return res;
        map<char,string>m;
        m.insert(make_pair('2', "abc"));
        m.insert(make_pair('3', "def"));
        m.insert(make_pair('4', "ghi"));
        m.insert(make_pair('5', "jkl"));
        m.insert(make_pair('6', "mno"));
        m.insert(make_pair('7', "pqrs"));
        m.insert(make_pair('8', "tuv"));
        m.insert(make_pair('9', "wxyz"));
        string tmp="";
        int idx = 0;
        dfs(digits, m, tmp, res, idx);

        return res;
    }
    void dfs(string& digits, map<char,string>&m, string& tmp, vector<string>& res, int idx) {
        if (tmp.size() == digits.size()) {
            res.emplace_back(tmp);
            return;
        }
        for (int i = 0; i < m[digits[idx]].size(); ++i) {
            tmp += m[digits[idx]][i];
            dfs(digits, m, tmp, res, idx + 1);
            tmp.pop_back();
        }
    }
};