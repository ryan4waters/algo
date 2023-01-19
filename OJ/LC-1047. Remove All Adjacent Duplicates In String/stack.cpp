class Solution {
public:
    string removeDuplicates(string s) {
        string res="";
        stack<char>mystack;
        for (auto ss:s) {
            if (mystack.empty() || ss != mystack.top()) {
                mystack.push(ss);
                cout<<mystack.top()<<endl;}
            else {mystack.pop();}
        }
        cout<<mystack.size()<<endl;
        while (!mystack.empty()) {
            res+=mystack.top();
            mystack.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
