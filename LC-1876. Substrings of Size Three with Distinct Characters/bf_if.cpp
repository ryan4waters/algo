class Solution {
public:
    int countGoodSubstrings(string s) {
    int len=s.size();
    if (len<3){return 0;}
    int num=0;
    for (int i=0;i<=len-3;i++){
    if (s[i]!=s[i+1]&&s[i+1]!=s[i+2]&&s[i]!=s[i+2]){num++;}
    }
    return num;
    }
};
