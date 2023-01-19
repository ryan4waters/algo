class Solution {
public:
    int firstUniqChar(string s) {
        for (int i=0;i<s.size();i++) {
            if (count(s.begin(),s.end(),s[i]) == 1) {return i;break;}
        }
        return -1;
    }
};
