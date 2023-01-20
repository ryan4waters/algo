#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string ss = "abcdabd";
    vector<int>next(ss.size(),0);
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
    for_each(next.begin(),next.end(),[](int val){
        cout<<val<<" ";
    });
    return 0;
}
