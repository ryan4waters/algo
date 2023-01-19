class Solution {
public:
    string reformatNumber(string number) {
        int len1=number.size();
        if (len1 <= 3) {return number;}
        string s="";
        for (const auto &c:number) {
            if (c != ' ' && c != '-') {
                s=s+c+' ';
            }
        }
        int len2=s.size();
        if (len2 % 3 == 0) {
            for (int i=0;i<len2;i+=2) {
                if (i == 4 || (i-4)%6==0) {
                    s[i+1]='-';
                }
            }
            s=s.substr(0,s.size()-1);
        } else {
            for (int j=0;j<len2-4;j+=2) {
                if (j == 4 || (j-4)%6==0) {
                    s[j+1]='-';
                }
            }
            s[len2-5]='-';
        }
        string res="";
        for (const auto &cc:s) {
            if (cc != ' ') {res+=cc;}
        }
        return res;
    }
};
