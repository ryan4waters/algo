class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
vector<int>vec;
        int len=nums.size();
        if (len==1 || k==0) {return false;}
      /*
      *I used vec.begin() to compare, unfortunately it can't check the last few elements in one for-loop, I believe have to add one another loop to check the last group. 
      *So directly counting the element[i] is better with less confusing to calculate the rule of for-loop, besides, never would worry about the last group.
      */
        for (int i=0;i<len;i++) {//I used 
            vec.push_back(nums[i]);
            if (count(vec.begin(),vec.end(),nums[i]) != 1) {return true;}
            if (vec.size()>k) {vec.erase(vec.begin());}
        }
        return false;
    }
};
