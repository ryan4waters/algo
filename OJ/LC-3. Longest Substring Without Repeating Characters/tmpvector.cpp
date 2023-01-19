class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") {return 0;}
        if (s.size() == 1) {return 1;}
        vector<char>v;
        vector<int>res;
        int tmp=0;
        int ct=0;
        for (int i=0;i<s.size();++i) {
            for (int j=i;j<s.size();++j) {
                if (count(v.begin(),v.end(),s[j]) == 0) {
                    v.push_back(s[j]);
                    ++ct;
                } else {
                    res.push_back(ct);
                    v.clear();
                    ct=0;
                    break;
                }
            }

        }
        sort(res.begin(),res.end(),greater<>());
        return res[0];
    }
};
