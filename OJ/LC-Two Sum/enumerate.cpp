class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len=nums.size();
        for (int i=0;i<len;i++){
            for (int j=i+1;j<len;j++){
                if ((nums[i]+nums[j])==target){
                    return{i,j};
                }
            }
        }
        return {};
    }
};

/*
Time Complexity: O(N^2), where (N^2) is the number of elements in the array. In the worst case, any two numbers in the array must be matched once.

Space Complexity: O(1).
*/
