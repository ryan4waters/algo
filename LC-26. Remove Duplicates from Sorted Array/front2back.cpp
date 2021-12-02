class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len=nums.size();
        if (len < 2) {return len;}
        int c=1;
        for (int j=0;j<len-1;j++){
            if (nums[j] != nums[j+1]) {nums[c]=nums[j+1];c++;}
        }
        return c;
    }
};
