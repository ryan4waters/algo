class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double fres=accumulate(nums.begin(),nums.begin()+k,0);
        double tmp=fres;
        for (int i=0;i<nums.size()-k;++i) {
            fres=fres-nums[i]+nums[i+k];
            tmp=max(fres,tmp);
        }
        return tmp/k;
    }
};
