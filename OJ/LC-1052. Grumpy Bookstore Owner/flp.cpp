/*the first i saw this problem, as you know the key is to figure when to use the SKILL. 
*So i decided to calculate the biggest consecutive unsatisfied customers' number WITHOUT THE SKILL USING, so i creat one vector named tmpv which could do that. The rest is math problem.
*NOTE:max_element() is great to use.
*/
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        vector<int>tmpv;
        for (int i=0;i<customers.size();i++) {
            tmpv.push_back(customers[i] * grumpy[i]);
        }
        int resangry=accumulate(tmpv.begin(),tmpv.end(),0);
        int resall=accumulate(customers.begin(),customers.end(),0);
        int temp=0;
        for (int j=0;j<minutes;j++) {
            temp+=tmpv[j];
        }
        vector<int> savev;
        savev.push_back(temp);
        for (int l=0,r=minutes-1;r<customers.size()-1;) {
            temp=temp-tmpv[l++]+tmpv[++r]; // here i used double pointer, one faster, one slower.
            savev.push_back(temp);
        }
        auto mymark=max_element(savev.begin(),savev.end());
        int vmark=mymark-savev.begin();
        
        int respeace=0;
        for (int k=vmark;k<vmark+minutes;k++) { // skill using.
            if (grumpy[k] == 1) {respeace+=customers[k];}
        }
        int res=resall-resangry+respeace;
        return res;
    }
};
