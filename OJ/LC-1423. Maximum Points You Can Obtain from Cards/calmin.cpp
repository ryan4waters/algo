class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
    int ct=cardPoints.size()-k;
    vector<int>::iterator it=cardPoints.begin();
    int res=accumulate(it,it+ct,0);
    int tmp=res;
    for (int i=0;i<k;i++) {
        tmp=tmp-cardPoints[i]+cardPoints[i+ct];
        res=min(res,tmp);
    }
    return (accumulate(cardPoints.begin(),cardPoints.end(),0)-res);
    }
};
