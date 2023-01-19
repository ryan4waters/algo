class Solution {
public:
    int maxScore(string s) {
        int len=s.size();
        vector<int>v(len-1);
        int num0=0;
        int num1=0;
        for (int i=0;i<len-1;++i) {
            num0=count(s.begin(),s.begin()+i+1,'0');
            num1=count(s.begin()+i+1,s.end(),'1');
            v.push_back(num0+num1);
        }
        sort(v.begin(),v.end(),greater<>());
        return v[0];
    }
};
