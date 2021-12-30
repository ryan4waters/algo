class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int>os;
        vector<int>js;
        vector<int>res;
        for(int i=0;i<nums.size();++i) {
            nums[i]%2 == 0?os.push_back(nums[i]):js.push_back(nums[i]);
        }
        for(int j=0;j<nums.size()/2;++j) {
            res.emplace_back(os[j]);
            res.emplace_back(js[j]);
        }
        return res;
    }
};
