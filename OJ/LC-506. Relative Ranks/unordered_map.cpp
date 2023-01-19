class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int>tmp=score;
        int len=score.size();
        vector<string>res;
        if (len == 1) {return {"Gold Medal"};}
        sort(tmp.begin(),tmp.end(),greater<int>());
        unordered_map<int,string>rank(len);
        rank[tmp[0]]="Gold Medal";
        rank[tmp[1]]="Silver Medal";
        if (len >= 3) {
            rank[tmp[2]]="Bronze Medal";
            for (int i=3;i<len;i++){
                rank[tmp[i]]=to_string(i+1);// '0'+i+1 if score.size() is too big, ascii operator would go wrong
            }
        } 
        for (int j=0;j<len;j++){
            res.push_back(rank[score[j]]);
        }
        return res;
    }
};
