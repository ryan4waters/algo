class Solution {
public:
    string longestPalindrome(string s) {
        int slen=s.size();
        if (slen == 1) {return s;}
        int len1=0;
        int len2=0;
        int maxlen=0;
        int leftp=0; // left pointer
        int rightp=0; //right pointer
        for (int i=0;i<slen;i++) {
            len1=mirror(s,i,i);
            len2=mirror(s,i,i+1);
            maxlen=max(max(len1,len2),maxlen); // update maxlen
            if (maxlen > rightp-leftp+1) { // update left and right pointer
                leftp=i-(maxlen-1)/2;
                rightp=i+maxlen/2;
            }
        }
        return s.substr(leftp,maxlen);
    }
private:
    int mirror(string s, int l,int r) { // calculate the length of mirror-string
        int L=l;
        int R=r;

        while (L>=0 && R<s.size() && s[L] == s[R]) { // note: judge L and R first. if go find s[L]/s[R], would cause overflow problem.
            L--;
            R++;
        }
        return R-L-1;// L and R plus 1 after the last while-loop
    }
};
