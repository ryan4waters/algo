class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
int len=nums.size();
unordered_set<int> myset;

for (int i=0;i<len;i++){
    if (myset.count(nums[i])){return true;}
    myset.insert(nums[i]);
    if (myset.size()>k){myset.erase(nums[i - k]);}//set is NOT equal to vector, .begin() or .end() can't be used.
}
return false;
}
};
