class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if (arr.size()-1 < k) {
            sort(arr.begin(),arr.end(),greater<>());
            return arr[0];
        }
        deque<int>mydeque;
        for (const auto a:arr) {
            mydeque.push_back(a);
        }
        unordered_map<int,int>mymap;
        int tmpmax=0;
        int tmpmin=0;
        for (;1;) {
            tmpmax=max(mydeque[0],mydeque[1]);
            tmpmin=min(mydeque[0],mydeque[1]);
            ++mymap[tmpmax];
            auto dpos=mydeque[0]<mydeque[1]?mydeque.begin():mydeque.begin()+1;
            mydeque.erase(dpos);
            mydeque.push_back(tmpmin);
            if (mymap[tmpmax] == k) {return tmpmax;}
        }
    }
};
