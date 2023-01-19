class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int num=cardPoints.size();
        int tmp=accumulate(cardPoints.end()-k,cardPoints.end(),0); // put the window at the end place
        int res=tmp; // initialize the result
        int l=num-k; // left pointer
        int r=num-1; // right pointer
        while (l < num) {
            tmp=tmp-cardPoints[l++%num]+cardPoints[++r%num];
            res=max(tmp,res);
        }
        return res;
    }
};
