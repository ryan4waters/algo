class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res=0;
        int tmp=0;
        for (int i=0;i<accounts.size();++i) {
            for (int j=0;j<accounts[0].size();++j) {
                tmp+=accounts[i][j];
            }
            res=max(tmp,res);
            tmp=0;
        }
        return res;
    }
};
