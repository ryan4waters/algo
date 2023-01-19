class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int onum=count(nums.begin(),nums.end(),0);
        int unonum=nums.size()-onum;
        int ct=0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i] != 0) {
                nums[ct]=nums[i];
                ct++;
            }
        }
        for (int j=unonum;j<nums.size();j++) {
            nums[j]=0;
        }
    }
};
