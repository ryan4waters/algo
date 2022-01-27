class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        multimap<int,int>m;
        set<int>sct;
        int ct=0;
        sort(nums.begin(),nums.end());
        for (int i=0;i<nums.size();++i){
            ct=count(nums.begin(),nums.end(),nums[i]);
            m.insert(make_pair(ct,nums[i]));
            sct.insert(ct);
            i+=ct-1;
        }
        vector<int>res;
        for (auto it=sct.begin();it!=sct.end();++it) {
            auto dit=m.equal_range(*it);
            if (dit.first != end(m)) {
                for (auto eit=dit.first;eit != dit.second;++eit) {
                    res.emplace_back(eit->second);
                }
            }
        }
        vector<int>fin;
        for (auto iter=res.end()-1;iter!=res.end()-k-1;--iter) {
            fin.emplace_back(*iter);
        }
        return fin;
    }
};
