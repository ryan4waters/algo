class Solution {
public:
    int firstUniqChar(string s) {
        for (int i=0;i<s.size();i++) {
            if (s.find(s[i]) == s.rfind(s[i])) {return i;break;}
        }
        return -1;
    }
};
