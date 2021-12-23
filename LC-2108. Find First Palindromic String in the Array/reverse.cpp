class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string tmp="";
        for (int i=0;i<words.size();i++) {
            tmp=words[i];
            reverse(tmp.begin(),tmp.end());
            if (tmp == words[i]) {return words[i];break;}
        }
        return "";
    }
};
