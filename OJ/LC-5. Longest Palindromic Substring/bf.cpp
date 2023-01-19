class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 1) {return s;}
        unordered_set<string>myset;
        string tmp="";
        string ttmp="";
        int len=s.size();
        for (int i=0;i<len;i++) {
            for (int j=1;j<len+1;j++) {
                tmp=s.substr(i,j);
                ttmp=tmp;
                reverse(ttmp.begin(),ttmp.end());
                if (tmp == ttmp) {myset.insert(tmp);}
            }
        }
        int ss=0;
        unordered_set<string>::iterator jj;
        for (auto j=myset.begin();j != myset.end();j++) {
            if ((*j).size() > ss) {ss=(*j).size();jj=j;}
        }
        return *jj;
    }
};
