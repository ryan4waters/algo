class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rownum=matrix.size();
        int colnum=matrix[0].size();
        vector<vector<int>>v;
        for (int m=0;m<rownum;m++) {
            v.push_back(vector<int>(colnum));
        }
        for (int i=0;i<rownum;i++) {
            for (int j=0;j<colnum;j++) {
                if (matrix[i][j] == 0) {
                    v[i][j]=1;
                }
            }
        }
        for (int k=0;k<rownum;k++) {
            for (int l=0;l<colnum;l++) {
                if (v[k][l]) {
                    for (int z=0;z<colnum;z++) {
                        matrix[k][z]=0;
                    }
                    for (int x=0;x<rownum;x++) {
                        matrix[x][l]=0;
                    }
                }
            }
        }
    }
};
