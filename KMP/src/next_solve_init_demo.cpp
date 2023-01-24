#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    string p = "abcdabd";
    vector<int>next(p.size(), 0);
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
    for_each(next.begin(), next.end(), [&](int val){
        cout << val << " ";
    });
    return 0;
}
