class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int>s;
        vector<int>v;
        int len=nums.size();
        for (int i=0;i<len;i++) {
            s.insert(nums[i]);
        }
        
        for (int j=1;j<len+1;j++) {
            set<int>::iterator it=s.begin();
            if (*it == j) {s.erase(*it);}
            else {v.push_back(j);}
        }
        return v;
    }
};
