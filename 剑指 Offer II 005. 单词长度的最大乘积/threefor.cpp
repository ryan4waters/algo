class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ct=0;
        int res=0;
        for (int i=0;i<words.size();i++) {
            for (int j=i+1;j<words.size();j++) {
                ct=0;
                for (int k=0;k<words[i].size();k++) {
                    if (find(words[j].begin(),words[j].end(),words[i][k]) != words[j].end()) {break;}
                    else {ct++;}
                }
                if (ct == words[i].size() && ct*words[j].size() > res) {res=ct*words[j].size();}
            }
        }
        return res;
    }
};
