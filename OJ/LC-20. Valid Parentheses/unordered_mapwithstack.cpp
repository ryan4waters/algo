class Solution {
public:
    bool isValid(string s) {
//deal with the special terms    
    int len=s.size();
    if (len%2 != 0) {return false;}
    if (s[0]==')' || s[0]=='}' || s[0]==']') {return false;}
    if (s=="()" || s=="{}" || s=="[]") {return true;}
      
//build unordered_map to match different char with key value
    unordered_map<char,int> mymap={
        {'(',1},
        {'{',2},
        {'[',3},
        {')',4},
        {'}',5},
        {']',6},
    };
    stack<char> mystack;

//traverse s to dump off matchup      
    for (auto c:s){
    int flag=mymap[c];
    if (flag<=3){mystack.push(c);}
    else if (!mystack.empty() && flag==mymap[mystack.top()]+3) {mystack.pop();}
    else {return false;}
    }
    if (mystack.empty()) {return true;}
    else {return false;}
}
};
