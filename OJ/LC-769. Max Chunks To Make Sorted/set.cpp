class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0;
        set<int>tmp;
        for (int i=0;i<arr.size();++i) {
            tmp.insert(arr[i]);
            auto it = tmp.end();
            --it;
            if (*it == i) {
                ++res;
                tmp.clear();
            }
        }
        return res;
    }
};
