#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class KMP
{
public:
    void GetKMPNextArr1(const string& ss) {
        next.resize(ss.size(),0);
        for (int sssr = ss.size() - 1; sssr > 0; --sssr) {
            for (int sssl = sssr; sssl > 0; --sssl) {
                int i = 0;
                for (int pos = sssl; pos <= sssr; ++pos, ++i) {
                    if (ss[i] != ss[pos]) {
                        break;
                    }
                }
                if (i == sssr - sssl + 1) {
                    next[sssr] = max(next[sssr],i);
                }
            }
        }
    }

    void GetKMPNextArr2(const string& ss) {
        this->next.resize(ss.size(), 0);
        int left = 0, right = 1;
        while (right < ss.size()) {
            if (ss[right] == ss[left]) {
                ++left;
                next[right] = left;
                ++right;
            } else if (left != 0) {
                left = next[left -1];
            } else {
                next[right] = 0;
                ++right;
                
            }
        }
    }

    vector<int> GetMasterStringStartIdx(const string& ms, const string& ss) {
        GetKMPNextArr1(ss);
        int midx = 0, sidx = 0;
        vector<int>ret;

        while (midx < ms.size()) {
            if (ms[midx] == ss[sidx]) {
                ++midx;
                ++sidx;
            } else if (sidx != 0) {
                sidx = next[sidx - 1];
            } else {
                ++midx;
            }

            if (sidx == ss.size()) {
                ret.emplace_back(midx - sidx);
                sidx = next[sidx - 1];
            }
        }
        return ret;
    }
private:
    vector<int>next;
};

int main()
{
    string ms = "abcdabdcdaabcda";
    string ss = "abc";
    KMP mykmp;
    vector<int>v = mykmp.GetMasterStringStartIdx(ms, ss);
    for_each(v.begin(),v.end(),[](int val) {
        cout<<val<<" ";
    });cout<<endl;

    return 0;
}