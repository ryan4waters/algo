class Solution {
public:
    string reverseWords(string s) {
        s+=' '; // to push the last word
        string res="";
        string tmp="";
        stack<string>mystack;
        for (int i=0;i<s.length();i++) {
            if (s[i] != ' ') {
                tmp+=s[i];
            } else {
                if (tmp.length() != 0) { // jump the consecutive space, make sure only words in mystack
                    mystack.push(tmp);
                    tmp="";
                }
            }
        }
        while (!mystack.empty()) {
            res+=mystack.top()+' ';
            mystack.pop();
        }
        return res.substr(0,res.length()-1);
    }
};
