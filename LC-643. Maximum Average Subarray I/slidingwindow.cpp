class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
    int len=nums.size();
    int sum=accumulate(nums.begin(),nums.begin()+k,0);
    int res=sum;
    for (int i=1;i<len-k+1;i++){
        sum=sum-nums[i-1]+nums[i+k-1];
        if (sum>=res) {res=sum;}//res=max(res,sum);
    }
    return (double)res/k;
    }
};
