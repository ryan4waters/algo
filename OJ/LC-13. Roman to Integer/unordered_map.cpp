class Solution {
public:
    int romanToInt(string s) {
    int len=s.size();
    int addin=0;
    unordered_map<char,int> mymap={
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000},
    };

    for (int i=0;i<len;i++){
        if (i<len-1 && mymap[s[i]]<mymap[s[i+1]]) {addin-=mymap[s[i]];}
        else addin+=mymap[s[i]];
    }
    return addin;
    }
};
