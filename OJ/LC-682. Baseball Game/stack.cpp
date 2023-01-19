class Solution {
public:
    int calPoints(vector<string>& ops) {
    int len=ops.size();
    int res=0;
    stack<int>mystack;
    for (int i=0;i<len;i++){
        if (ops[i] == "C") {mystack.pop();}
        else if (ops[i] == "D") {mystack.push(mystack.top()*2);}
        else if (ops[i] == "+") {
            int stop=mystack.top();
            mystack.pop();
            int sstop=mystack.top();
            int tmp=stop+sstop;
            mystack.push(stop);
            mystack.push(tmp);
            }
        else {mystack.push(atoi(ops[i].c_str()));}
    }
    while (!mystack.empty()){
        res+=mystack.top();
        mystack.pop();
    }
    return res;
    }
};
