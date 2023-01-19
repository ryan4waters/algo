class Solution {
public:  
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        // if (accumulate(price.begin(),price.end(),0) == 0) {
        //     return 0;
        // }
        this->res=INT_MAX;
        for (const auto& r:special) {
            if (avacheck(r,needs) == false) {
                continue;
            }
            if (inner_product(r.begin(),r.begin()+r.size()-1,price.begin(),0) < r.back()) {
                continue;
            }    
            avaspecial.emplace_back(vector<int>());
            for (const auto& c:r) {
                avaspecial[avaspecial.size()-1].emplace_back(c);
            }
        }
        mydfs(needs,0,price);
        return res;
    }  
private:
    bool avacheck(const vector<int>&rowspecial,const vector<int>&checkneeds) {
        for (int k=0;k<checkneeds.size();++k) {
            if (rowspecial[k] > checkneeds[k]) {
                return false;
            }
        }
        return true;
    }
    void mydfs(vector<int>&myneeds,int tmpsum,const vector<int>&ctprice) {
        bool checkflag=false;
        if (tmpsum >= res) {
            return;
        }
        if (accumulate(myneeds.begin(),myneeds.end(),0) == 0) {
            res=min(res,tmpsum);
            return;
        }
        for (int m=0;m<avaspecial.size();++m) {
            if (avacheck(avaspecial[m],myneeds) == true) {
                checkflag=true;
                for (int n=0;n<avaspecial[0].size()-1;++n) {
                    myneeds[n]-=avaspecial[m][n];
                }
                mydfs(myneeds,tmpsum+avaspecial[m].back(),ctprice);
                for (int n=0;n<avaspecial[0].size()-1;++n) {
                    myneeds[n]+=avaspecial[m][n];
                }
            }    
        }
        if (checkflag == false) {
            for (int i=0;i<myneeds.size();++i) {
                tmpsum+=myneeds[i] * ctprice[i];
            }
            res=min(res,tmpsum);
        }
    }
    int res;
    vector<vector<int>>avaspecial;
};
