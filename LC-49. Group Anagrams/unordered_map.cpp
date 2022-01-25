class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<int,string>m;
        vector<string>d;
        string tmps="";
        for (int i=0;i<strs.size();++i) {
            tmps=strs[i];
            m.insert(make_pair(i,tmps));
            sort(tmps.begin(),tmps.end());
            d.emplace_back(tmps);
        }
        int col=0;
        for (int j=0;j<strs.size();++j) {
            if (d[j] == "C") {
                continue;
            }
            res.emplace_back(vector<string>());
            res[col].emplace_back(m[j]);
            for (int k=j+1;k<strs.size();++k) {
                if (d[j] == d[k]) {
                    res[col].emplace_back(m[k]);
                    d[k]="C";
                }
            }
            ++col;
        }
        return res;
    }
};
