class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle=="") {return 0;}
        if (needle.size()>haystack.size()) {return -1;}

        int num=0; 
        int n=0;       
        if (needle.size()==haystack.size()) {
            for (int i=0;i<needle.size();i++) {
                if (needle[i]==haystack[i]) {num++;}
                else {return -1;}
                if (num==needle.size()) {return 0;}
            }
        }

        for (int i=0;i<(haystack.size()-needle.size()+1);i++){
            string s="";
            for (int j=i;j<i+needle.size();j++){s.push_back(haystack[j]);}
            for (int k=0;k<needle.size();k++){
                if (s[k]==needle[k]) {n++;}
                else {break;}
            }
            if (n==needle.size()) {return i;}
            n=0;
        }
        return -1;
    }
};
