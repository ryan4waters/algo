class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int m=mat.size();
    int n=mat[0].size();
    if (m*n!=r*c){return mat;}

    vector<vector<int>> oldvec(r,vector<int>(c,0));
    int row=0;
    int col=0;
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            oldvec[row][col]=mat[i][j];
            col++;
            if (col==c){row+=1;col=0;}
        }
    }
    return oldvec;
    }
};
