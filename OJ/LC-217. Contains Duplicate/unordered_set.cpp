class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       unordered_set<int> myset;
       for (auto c:nums){
           if (myset.find(c)!=myset.end()){return true;}
           myset.insert(c);
       }
       return false;
    }
};
