class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();
        int len2=nums2.size();
        vector<int>res(len1);
        vector<int>::iterator it=nums2.begin();
        for (int i=0;i<len1;i++) {
            it=find(nums2.begin(),nums2.end(),nums1[i])+1;
            if (it ==nums2.end()) {res[i]=-1;}
            while (it != nums2.end()) {
                if (*it > nums1[i]) {res[i]=*it;break;}
                it++;
                if (it == nums2.end()) {res[i]=-1;}            
            }
        }
        return res;
    }
};
