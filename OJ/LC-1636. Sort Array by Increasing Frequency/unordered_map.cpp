class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mymap;
        int ct=0;
        sort(nums.begin(),nums.end());
        for (int i=0;i<nums.size();++i) {
            ct=count(nums.begin(),nums.end(),nums[i]);
            mymap.insert(make_pair(nums[i],ct));
            i+=ct-1;
        }
        sort(nums.begin(),nums.end(),[&mymap](int a,int b){
            if (mymap[a] == mymap[b]) {return a>b;}
            else {return mymap[a]<mymap[b];}
        });
        return nums;
    }
};
