class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int len=index.size();
        deque<int>mydeque;
        vector<int>res;
        for (int i=0;i<len;++i) {
            mydeque.emplace(mydeque.begin()+index[i],nums[i]);
        }
        for (int j=0;j<len;++j) {
            res.push_back(mydeque[j]);
        }
        return res;
    }
};
