class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ct=0;
        for (auto &c:nums) {
            if (c == val) {
                c=-1;
                ++ct;
            }
        }
        sort(nums.begin(),nums.end(),greater<int>());
        return nums.size()-ct;
    }
};
