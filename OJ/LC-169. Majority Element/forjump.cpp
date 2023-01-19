class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ct=0;
        sort(nums.begin(),nums.end());
        for (int i=0;i<nums.size();i++) {
            ct =count(nums.begin(),nums.end(),nums[i]);
            if (ct > nums.size()/2) {return nums[i];}
            else {i+=ct;}
        }
        return -1;
    }
};
