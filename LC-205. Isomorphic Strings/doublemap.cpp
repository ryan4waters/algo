class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>st;
        unordered_map<char,char>ts;
        for (int i=0;i<s.size();++i) {
            st[s[i]] = t[i];
            ts[t[i]] = s[i];
        }
        for (int i=0;i<s.size();++i) {
            if (st[s[i]] != t[i]) {return false;}
            if (ts[t[i]] != s[i]) {return false;}
        }
        return true;
    }
};
