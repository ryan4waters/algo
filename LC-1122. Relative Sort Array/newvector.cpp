class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int len1=arr1.size();
        int len2=arr2.size();
        int ncount=0;;
        int cc=0;
        int nall=0;
        vector<int> arr3=arr1;
        for (int i=0;i<len2;i++){
            ncount=count(arr1.begin(),arr1.end(),arr2[i]);
            nall+=ncount;
            while (cc<nall) {
                arr3[cc]=arr2[i];
                cc++;
            }
        }
        int tmpcount=nall;
        for (int j=0;j<len1;j++){
            if (count(arr2.begin(),arr2.end(),arr1[j]) == 0){
                arr3[tmpcount]=arr1[j];
                tmpcount++;
            }
        }
        sort(arr3.begin()+nall,arr3.end(),less<int>());
        return arr3;
    }
};
