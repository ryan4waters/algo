class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int len=nums.size();

    vector<int> vec(len);
    vec[0]=nums[0];
    int res=vec[0];

    for (int i=1;i<len;i++){
      vec[i]=max(vec[i-1]+nums[i],nums[i]);
      res=max(vec[i],res);
    }
    return res;
    }
};
