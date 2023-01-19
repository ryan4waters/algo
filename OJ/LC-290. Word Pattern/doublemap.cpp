class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>mcs;
        unordered_map<string,char>msc;
        vector<string>v;
        string tmp="";
        stringstream ss(s);
        while (getline(ss,tmp,' ')) { // spilt the string
            v.emplace_back(tmp);
        }
        if (v.size() != pattern.size()) {
            return false;
        }
        for (int i=0;i<pattern.size();++i) {
            mcs[pattern[i]] = v[i];
            msc[v[i]] = pattern[i];
        }
        for (int j=0;j<pattern.size();++j) {
            if (mcs[pattern[j]] != v[j]) {
                return false;
            }
            if (msc[v[j]] != pattern[j]) {
                return false;
            }
        }
        return true;
    }
};
