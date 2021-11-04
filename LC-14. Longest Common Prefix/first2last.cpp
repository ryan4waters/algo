class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) {return "";};

        string scom=strs[0];
        string stmp;
        for (int i=1;i<strs.size();i++){
            stmp=scom;
            scom="";
            for (int j=0;j<strs[i].size();j++){
                if (stmp[j]==strs[i][j]){scom+=stmp[j];}
                else {break;}
            }
            if (scom=="") {return "";}
        }
        return scom;
    }
};
