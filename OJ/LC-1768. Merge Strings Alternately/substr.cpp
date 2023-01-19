class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s;
        int minlen=min(word1.size(),word2.size());
        for (int i=0;i<minlen;i++){
            s=s+word1[i]+word2[i];
        }
        if (word1.size()>word2.size()) {s=s+word1.substr(word2.size());}
        if (word1.size()<word2.size()) {s=s+word2.substr(word1.size());}

        return s;
    }
};
