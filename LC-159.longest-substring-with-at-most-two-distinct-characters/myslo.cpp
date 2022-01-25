class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        string tmps=" ";
        for (const auto& c:s) {
            if (c != tmps[tmps.size()-1]) {
                tmps += ' ';
            }
            tmps += c;
        }
        tmps = tmps.substr(2);
        stringstream ss(tmps);
        string os="";
        vector<int>vct;
        vector<char>vc;
        while (getline(ss,os,' ')) {
            vct.emplace_back(os.size());
            vc.emplace_back(os[0]);
        }
        set<char>myset;
        int tmp=0;
        int res=0;
        for (int i=0;i<vc.size();++i) {
            for (int j=i;j<vc.size();++j) {
                myset.insert(vc[j]);
                if (myset.size() > 2) {
                    break;
                }
                tmp=accumulate(vct.begin()+i,vct.begin()+j+1,0);
                res=max(tmp,res);
            }
            myset.clear();
        }
        return res;
    }
};
