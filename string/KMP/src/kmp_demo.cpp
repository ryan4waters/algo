#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class KMP
{
public:
    void GetKMPNextArrInit(const string& p) {
        next.resize(p.size(), 0);
        for (int pr = p.size() - 1; pr > 0; --pr) {
            for (int pl = pr; pl > 0; --pl) {
                int i = 0;
                for (int pos = pl; pos <= pr; ++pos, ++i) {
                    if (p[i] != p[pos]) {
                        break;
                    }
                }
                if (i == pr - pl + 1) {
                    next[pr] = max(next[pr], i);
                }
            }
        }
    }

    void GetKMPNextArrQuick(const string& p) {
        this->next.resize(p.size(), 0);
        int now = 0, x = 1;
        while (x < p.size()) {
            if (p[x] == p[now]) {
                ++now;
                next[x] = now;
                ++x;
            } else if (now != 0) {
                now = next[now -1];
            } else {
                next[x] = 0;
                ++x;
                
            }
        }
    }

    vector<int> GetMasterStringStartIdx(const string& t, const string& p) {
        GetKMPNextArrQuick(p);
        int tidx = 0, pidx = 0;
        vector<int>ret;

        while (tidx < t.size()) {
            if (t[tidx] == p[pidx]) {
                ++tidx;
                ++pidx;
            } else if (pidx != 0) {
                pidx = next[pidx - 1];
            } else {
                ++tidx;
            }

            if (pidx == p.size()) {
                ret.emplace_back(tidx - pidx);
                pidx = next[pidx - 1];
            }
        }
        return ret;
    }
private:
    vector<int>next;
};

int main()
{
    string t = "abcdabdcdaabcda";
    string p = "abc";
    KMP mykmp;
    vector<int>v = mykmp.GetMasterStringStartIdx(t, p);
    for_each(v.begin(), v.end(), [&](int val) {
        cout << val << " ";
    }); cout << endl;

    return 0;
}