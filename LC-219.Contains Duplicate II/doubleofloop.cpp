class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
int m=0;
int len=nums.size();

for (int i=0;i<len;i++){
    for (int j=i+1;j<len;j++){
        if (nums[i]==nums[j]){
            if (abs(i-j)<=k){return true;}
        }
        m++;
    }
}
if (m==(len*(len-1))) {return false;}
return 0;
}
};
