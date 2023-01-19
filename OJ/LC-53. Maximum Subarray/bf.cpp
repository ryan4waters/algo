class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size()==1) {return nums[0];}
        int max=INT_MIN;
        for (int i=0;i<nums.size();i++){
        int sum=0;
            for (int j=i;j<nums.size();j++){
                sum+=nums[j];
                if (sum>max){max=sum;}
            }
        }
        return max;
    }
};
