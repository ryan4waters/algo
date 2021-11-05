class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for (int i=0;i<nums.size();i++){
            if (count(nums.begin(),nums.end(),nums[i])>=2) {return true;}
        }
        return false;
    }
};
