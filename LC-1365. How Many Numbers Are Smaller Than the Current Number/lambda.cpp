class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>res;
        int tmp=0;
        for (int i=0;i<nums.size();++i) {
            tmp=count_if(nums.begin(),nums.end(),[&](int a)->bool{
                return a<nums[i];
            });
            res.push_back(tmp);
            tmp=0;
        }
        return res;
    }
};
