class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<char>vs;
        vector<char>vt;
        for (int i=0;i<s.size();i++) {
            vs.push_back(s[i]);
        }
        for (int j=0;j<t.size();j++) {
            vt.push_back(t[j]);
        }
        sort(vs.begin(),vs.end());
        sort(vt.begin(),vt.end());

        if (vs == vt) {return true;}
        else {return false;}
    }
};
