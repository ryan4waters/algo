class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int,string>m;
        m.insert(pair<int,string>(0,"Gold Medal"));
        m.insert(pair<int,string>(1,"Silver Medal"));
        m.insert(pair<int,string>(2,"Bronze Medal"));
        vector<int>tmp=score;
        vector<string>res(score.size());
        sort(tmp.begin(),tmp.end(),greater<int>());
        int mymark=0;
        for (int i=0;i<score.size();i++) {
            mymark=calmark(score,tmp,i);
            if (i < 3) {res[mymark]=m[i];}
            else {res[mymark]=to_string(i+1);}
        }
        return res;
    }
private:
    int calmark(vector<int>&v1,vector<int>&v2,int x) {
        int cct=0;
        auto it=find(v1.begin(),v1.end(),v2[x]);
        auto itct=v1.begin();
        while (itct != it) {
            itct++;
            cct++;
        }
        return cct;
    }
};
