class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1;
        vector<int>v;
        for (auto c:nums1) {s1.insert(c);}
        int it=0;
        while (it < nums2.size()) {
            if (find(s1.begin(),s1.end(),nums2[it]) != s1.end()) {v.push_back(nums2[it]);s1.erase(nums2[it]);}
            it++;
        }
        return v;
    }
};
