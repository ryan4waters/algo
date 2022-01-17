class Solution {
public:
    string reverseVowels(string s) {
        stack<char>ms=myjudge(s);
        for (int j=0;j<s.size();++j) {
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U') {
                s[j] = ms.top();
                ms.pop();
            }
        }
        return s;
    }
private:
    stack<char> myjudge(string str) {
        stack<char>mystack;
        for (int i=0;i<str.size();++i) {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
                mystack.push(str[i]);
            }
        }
        return mystack;
    }
};
