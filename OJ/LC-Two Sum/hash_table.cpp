class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

/*
Time Complexity: O(N), where N is the number of elements in the array. For each element x, we can find target-x by O(1).

Space Complexity: O(N), where N is the number of elements in the array. Mainly the overhead of the hash table.
*/
