class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int>res;
        map<int,int>mymap;
        for (int i=1;i<rounds.size();++i) { //make the map
            if (rounds[i-1]-rounds[i] > 0) {
                for (int j=rounds[i-1];j<=n;++j) {
                    ++mymap[j];
                }
                for (int k=1;k<=rounds[i];++k) {
                    ++mymap[k];
                }
            }
            else {
                for (int l=rounds[i-1];l<=rounds[i];++l) {
                    ++mymap[l];
                }
            }
        }
        for (int de=1;de<rounds.size()-1;++de) {
            --mymap[rounds[de]];
        }
        
        vector<pair<int,int>>tv; //sort map and cal the maxnum
        sortmap(mymap,tv);
        auto mct=[&](int maxct)->int{
        for (const auto &tvv:tv) {
            if (tvv.second == tv[0].second) {++maxct;}
            else {break;}
        }
        return maxct;};
        int mn=0;
        int maxnum=mct(mn);

        for (auto it=tv.begin();it<tv.begin()+maxnum;++it) { //make the result vector
            res.push_back(it->first);
        }
        sort(res.begin(),res.end());
        return res;
    }
private:
    static bool comp(const pair<int,int>&left,const pair<int,int>&right) { //dont forget static 
        return left.second > right.second;
    }

    void sortmap(map<int,int>&sm,vector<pair<int,int>>&sv) {
        for (auto curr=sm.begin();curr != sm.end();++curr) {
            sv.push_back(make_pair(curr->first,curr->second));
        }
        sort(sv.begin(),sv.end(),comp);
    }
};
